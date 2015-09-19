// Modified Animated_Icon.cc - Vieri Di Paola dipaola@cli.di.unipi.it
#include <Fl/Fl.H>
#include "Animated_Icon.h"

int gif2xpm(
    const char *infname,// filename for error messages
    FILE *GifFile,	// file to read
    char*** datap,	// return xpm data here
    int** lengthp,	// return line lengths here
    int inumber,	// which image in movie (0 = first)
    int* g_width,	// gif width - Modified
    int* g_height	// gif height - Modified - Go to end of file
) {

  {char b[6];
  if (fread(b,1,6,GifFile)<6) return 0; /* quit on eof */
  if (b[0]!='G' || b[1]!='I' || b[2] != 'F') {
    fprintf(stderr,"%s is not a GIF file.\n", infname); return 0;}
  if (b[3]!='8' || b[4]>'9' || b[5]!= 'a')
    fprintf(stderr,"%s is version %c%c%c.\n",infname,b[3],b[4],b[5]);
  }

  int Width; GETSHORT(Width);
  int Height; GETSHORT(Height);

  uchar ch = NEXTBYTE;
  char HasColormap = ((ch & 0x80) != 0);
  int BitsPerPixel = (ch & 7) + 1;
  int ColorMapSize = 1 << BitsPerPixel;
  // int OriginalResolution = ((ch>>4)&7)+1;
  // int SortedTable = (ch&8)!=0;
  NEXTBYTE; // Background Color index
  NEXTBYTE; // Aspect ratio is N/64

  // Read in global colormap:
  uchar transparent_pixel = 0;
  char has_transparent = 0;
  uchar Red[256], Green[256], Blue[256]; /* color map */
  if (HasColormap) {
    for (int i=0; i < ColorMapSize; i++) {
      Red[i] = NEXTBYTE;
      Green[i] = NEXTBYTE;
      Blue[i] = NEXTBYTE;
    }
  } else {
    fprintf(stderr,"%s does not have a colormap.\n", infname);
    for (int i = 0; i < ColorMapSize; i++)
      Red[i] = Green[i] = Blue[i] = (i*256+ColorMapSize-1)/ColorMapSize;
  }

  int CodeSize;		/* Code size, init from GIF header, increases... */
  char Interlace;

  for (;;) {

    int i = NEXTBYTE;
    if (i<0) {fprintf(stderr,"%s: unexpected EOF\n",infname); return 0;}
    int blocklen;

    //  if (i == 0x3B) return 0;  eof code

    if (i == 0x21) {		// a "gif extension"

      ch = NEXTBYTE;
      blocklen = NEXTBYTE;

      if (ch==0xF9 && blocklen==4) { // Netscape animation extension

	char bits;
	bits = NEXTBYTE;
	NEXTBYTE; NEXTBYTE; // GETSHORT(delay);
	transparent_pixel = NEXTBYTE;
	if (bits & 1) has_transparent = 1;
	blocklen = NEXTBYTE;

      } else if (ch == 0xFF) { // Netscape repeat count
	;

      } else if (ch == 0xFE) { //Gif Comment
#if 0
	if(blocklen>0) {
	  char *comment=new char[blocklen+1];
	  int l;
	  for(l=0;blocklen;l++,blocklen--)
	    comment[l]=NEXTBYTE;
	  comment[l]=0;
	  fprintf(stderr,"%s: Gif Comment: '%s'\n", infname, comment);
	  delete comment;
	  NEXTBYTE; //End marker
	}
#endif
      } else {
	fprintf(stderr,"%s: unknown gif extension 0x%02x\n", infname, ch);

      }

    } else if (i == 0x2c) {	// an image

      NEXTBYTE; NEXTBYTE; // GETSHORT(x_position);
      NEXTBYTE; NEXTBYTE; // GETSHORT(y_position);
      GETSHORT(Width);
      GETSHORT(Height);
      ch = NEXTBYTE;
      Interlace = ((ch & 0x40) != 0);
      if (ch&0x80) {
	// read local color map
	int n = 1<<((ch&7)+1); // does this replace ColorMapSize ??
	for (i=0; i < n; i++) {
	  Red[i] = NEXTBYTE;
	  Green[i] = NEXTBYTE;
	  Blue[i] = NEXTBYTE;
	}
      }
      CodeSize = NEXTBYTE+1;

      if (!inumber--) break; // okay, this is the image we want
      blocklen = NEXTBYTE;

    } else {
      fprintf(stderr,"%s: unknown gif code 0x%02x\n", infname, i);
      blocklen = 0;
    }

    // skip the data:
    while (blocklen>0) {while (blocklen--) {NEXTBYTE;} blocklen=NEXTBYTE;}
  }

  uchar *Image = new uchar[Width*Height];
  if (!Image) {
    fprintf (stderr, "Insufficient memory\n");
    exit (2);
  }
  int YC = 0, Pass = 0; /* Used to de-interlace the picture */
  uchar *p = Image;
  uchar *eol = p+Width;

  int InitCodeSize = CodeSize;
  int ClearCode = (1 << (CodeSize-1));
  int EOFCode = ClearCode + 1;
  int FirstFree = ClearCode + 2;
  int FinChar = 0;
  int ReadMask = (1<<CodeSize) - 1;
  int FreeCode = FirstFree;
  int OldCode = ClearCode;

  // tables used by LZW decompresser:
  short int Prefix[4096];
  uchar Suffix[4096];

  int blocklen = NEXTBYTE;
  uchar thisbyte = NEXTBYTE; blocklen--;
  int frombit = 0;

  for (;;) {

/* Fetch the next code from the raster data stream.  The codes can be
 * any length from 3 to 12 bits, packed into 8-bit bytes, so we have to
 * maintain our location as a pointer and a bit offset.
 * In addition, gif adds totally useless and annoying block counts
 * that must be correctly skipped over. */
    int CurCode = thisbyte;
    if (frombit+CodeSize > 7) {
      if (blocklen <= 0) {
	blocklen = NEXTBYTE;
	if (blocklen <= 0) break;
      }
      thisbyte = NEXTBYTE; blocklen--;
      CurCode |= thisbyte<<8;
    }
    if (frombit+CodeSize > 15) {
      if (blocklen <= 0) {
	blocklen = NEXTBYTE;
	if (blocklen <= 0) break;
      }
      thisbyte = NEXTBYTE; blocklen--;
      CurCode |= thisbyte<<16;
    }
    CurCode = (CurCode>>frombit)&ReadMask;
    frombit = (frombit+CodeSize)%8;

    if (CurCode == ClearCode) {
      CodeSize = InitCodeSize;
      ReadMask = (1<<CodeSize) - 1;
      FreeCode = FirstFree;
      OldCode = ClearCode;
      continue;
    }

    if (CurCode == EOFCode) break;

    uchar OutCode[1025]; // temporary array for reversing codes
    uchar *tp = OutCode;
    int i;
    if (CurCode < FreeCode) i = CurCode;
    else if (CurCode == FreeCode) {*tp++ = FinChar; i = OldCode;}
    else {fprintf(stderr,"%s : LZW Barf!\n",infname); break;}

    while (i >= ColorMapSize) {*tp++ = Suffix[i]; i = Prefix[i];}
    *tp++ = FinChar = i;
    while (tp > OutCode) {
      *p++ = *--tp;
      if (p >= eol) {
	if (!Interlace) YC++;
	else switch (Pass) {
	case 0: YC += 8; if (YC >= Height) {Pass++; YC = 4;} break;
	case 1: YC += 8; if (YC >= Height) {Pass++; YC = 2;} break;
	case 2: YC += 4; if (YC >= Height) {Pass++; YC = 1;} break;
	case 3: YC += 2; break;
	}
	if (YC>=Height) YC=0; /* cheap bug fix when excess data */
	p = Image + YC*Width;
	eol = p+Width;
      }
    }

    if (OldCode != ClearCode) {
      Prefix[FreeCode] = OldCode;
      Suffix[FreeCode] = FinChar;
      FreeCode++;
      if (FreeCode > ReadMask) {
	if (CodeSize < 12) {
	  CodeSize++;
	  ReadMask = (1 << CodeSize) - 1;
	}
	else FreeCode--;
      }
    }
    OldCode = CurCode;
  }

  // We are done reading the file, now convert to xpm:

  // allocate line pointer arrays:
  char** data = new char*[Height+3];
  *datap = data;
  int* length = new int[Height+2];
  *lengthp = length;

  // transparent pixel must be zero, swap if it isn't:
  if (has_transparent && transparent_pixel != 0) {
    // swap transparent pixel with zero
    p = Image+Width*Height;
    while (p-- > Image) {
      if (*p==transparent_pixel) *p = 0;
      else if (!*p) *p = transparent_pixel;
    }
    uchar t;
    t = Red[0]; Red[0] = Red[transparent_pixel]; Red[transparent_pixel] = t;
    t =Green[0];Green[0]=Green[transparent_pixel];Green[transparent_pixel]=t;
    t =Blue[0];Blue[0] =Blue[transparent_pixel];Blue[transparent_pixel] = t;
  }

  // find out what colors are actually used:
  uchar used[256]; uchar remap[256];
  int i;
  for (i = 0; i < ColorMapSize; i++) used[i] = 0;
  p = Image+Width*Height;
  while (p-- > Image) used[*p] = 1;

  // remap them to start with printing characters:
  int base = has_transparent && used[0] ? ' ' : ' '+1;
  int numcolors = 0;
  for (i = 0; i < ColorMapSize; i++) if (used[i]) {
    remap[i] = base++;
    numcolors++;
  }

  // write the first line of xpm data (use suffix as temp array):
  length[0] = sprintf((char*)(Suffix),
		      "%d %d %d %d",Width,Height,-numcolors,1);
  data[0] = new char[length[0]+1];
  strcpy(data[0], (char*)Suffix);

  // write the colormap
  length[1] = 4*numcolors;
  data[1] = (char*)(p = new uchar[4*numcolors]);
  for (i = 0; i < ColorMapSize; i++) if (used[i]) {
    *p++ = remap[i];
    *p++ = Red[i];
    *p++ = Green[i];
    *p++ = Blue[i];
  }

  // remap the image data:
  p = Image+Width*Height;
  while (p-- > Image) *p = remap[*p];

  // split the image data into lines:
  for (i=0; i<Height; i++) {
    data[i+2] = (char*)(Image + i*Width);
    length[i+2] = Width;
  }

  data[Height+2] = 0; // null to end string array

  *g_width = Width;  // Modified
  *g_height = Height;

  return 1;
}



Animated_Icon::Animated_Icon(int X, int Y, int W, int H, const char *L) : Fl_Box(X,Y,W,H,L)
{
	first = current = 0;
	fir = cur = 0;
	running_ = 0;
}

Animated_Icon::~Animated_Icon()
{
	icon_list *l, *n;
	data_list *dl, *dn;

	stop();
	l = first;
	while (l) {
		n = l->next;
		delete l->icon;
		delete l;
		l = n;
	}

	dl = fir;
	while (dl) {
		dn = dl->nex;
		delete dl->data;
		delete dl;
		dl = dn;
	}
}

void Animated_Icon::add(Fl_Pixmap *pm, float d)
{
        icon_list *l = new icon_list;
	l->icon = pm;
	l->delay = d;
	l->next = 0;

	if (first == 0) {
		first = current = l;
	} else {
		l->next = current->next;
		current->next = l;
		current = l;
	}
}

void Animated_Icon::mem_gif( float DD )
{
	  if (g_a_w > n_g_a_w) n_g_a_w = g_a_w;
	  if (g_a_h > n_g_a_h) n_g_a_h = g_a_h;

          data_list *dl = new data_list;
          dl->data = dataglob;
	  dl->linelength = linelengthglob;
	  dl->nex = 0;

	  if (fir == 0) {
		  fir = cur = dl;
	  } else {
		  dl->nex = cur->nex;
		  cur->nex = dl;
		  cur = dl;
	  }
          add(new Fl_Pixmap(dl->data), DD);
}

void Animated_Icon::load_animated_gif(char* giff, float D, uchar direction, uchar g_a_r)
{
        n_g_a_w = 0;
        n_g_a_h = 0;

        GIFfile=fopen(giff,"rb");
        if (GIFfile==NULL) return;

        if (direction == 1) {
        maxframes=0;
        while (gif2xpm(giff,GIFfile,&dataglob,&linelengthglob,maxframes,&g_a_w,&g_a_h)) { maxframes++; rewind(GIFfile); }
        maxframes--;
        for (int i=maxframes;i>=0; i--) {
          gif2xpm(giff,GIFfile,&dataglob,&linelengthglob,i,&g_a_w,&g_a_h);
	  mem_gif(D);
	  rewind(GIFfile);
        }
        fclose(GIFfile);
        if (g_a_r == 1) resize(x()-n_g_a_w/2,y()-n_g_a_h/2,n_g_a_w,n_g_a_h);
        if (g_a_r == 2) resize(x(),y(),n_g_a_w,n_g_a_h);
        if (g_a_r == 3) resize(x()-n_g_a_w,y(),n_g_a_w,n_g_a_h);
        if (g_a_r == 4) resize(x(),y()-n_g_a_h,n_g_a_w,n_g_a_h);
        if (g_a_r == 5) resize(x()-n_g_a_w,y()-n_g_a_h,n_g_a_w,n_g_a_h);
        return;
        }

        maxframes = 0;
        while (gif2xpm(giff,GIFfile,&dataglob,&linelengthglob,maxframes,&g_a_w,&g_a_h))
        {
	  mem_gif(D);
          maxframes++;
          rewind(GIFfile);
        }
        maxframes--;
        fclose(GIFfile);
        if (g_a_r == 1) resize(x()-n_g_a_w/2,y()-n_g_a_h/2,n_g_a_w,n_g_a_h);
        if (g_a_r == 2) resize(x(),y(),n_g_a_w,n_g_a_h);
        if (g_a_r == 3) resize(x()-n_g_a_w,y(),n_g_a_w,n_g_a_h);
        if (g_a_r == 4) resize(x(),y()-n_g_a_h,n_g_a_w,n_g_a_h);
        if (g_a_r == 5) resize(x()-n_g_a_w,y()-n_g_a_h,n_g_a_w,n_g_a_h);
}

void Animated_Icon::icon_cb(Animated_Icon *a)
{
	icon_list *current = a->current;
	if (current->next == 0) {
		current = a->first;
	} else {
		current = current->next;
	}
	a->current = current;
	current->icon->label(a);
 	a->redraw();
	Fl::add_timeout(current->delay,
		(void (*)(void *))Animated_Icon::icon_cb, (void *)a);
}

void Animated_Icon::clear_animation()
{
	icon_list *l, *n;
	data_list *dl, *dn;

	stop();
	l = first;
	while (l) {
		n = l->next;
		delete l->icon;
		delete l;
		l = n;
	}

	dl = fir;
	while (dl) {
		dn = dl->nex;
		delete dl->data;
		delete dl;
		dl = dn;
	}

	first = current = 0;
	fir = cur = 0;
	running_ = 0;
}

void Animated_Icon::start()
{
	if (current == 0) {
		return;
	}
	current->icon->label(this);
	redraw();
	Fl::add_timeout(current->delay,
		(void (*)(void *))icon_cb, (void *)this);
	running_ = 1;
}

void Animated_Icon::stop()
{
	Fl::remove_timeout((void (*)(void *))icon_cb, (void *)this);
	running_ = 0;
}

void Animated_Icon::set(int n, uchar T)
{
        if (T==1) box(FL_FLAT_BOX);    // allows display of transparent gifs
       else box(FL_NO_BOX);    // allows display of non-transparent gifs without flickering

	icon_list *l = first;

	if (n < 0 || l == 0) return;

        while (n--) {
		l = l->next;
		if (l == 0) return;
	}

	l->icon->label(this);
	current = l;
}
