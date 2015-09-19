// Modified Animated_Icon.h - Vieri Di Paola dipaola@cli.di.unipi.it
#ifndef Animated_Icon_h
#define Animated_Icon_h

#include <Fl/Fl_Box.H>
#include <Fl/Fl_Pixmap.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

#define NEXTBYTE getc(GifFile)
#define GETSHORT(var) var = NEXTBYTE; var += NEXTBYTE << 8

int gif2xpm(
    const char *infname,// filename for error messages
    FILE *GifFile,	// file to read
    char*** datap,	// return xpm data here
    int** lengthp,	// return line lengths here
    int inumber,	// which image in movie (0 = first)
    int* g_width,	// gif width - Modified
    int* g_height	// gif height - Modified - Go to end of file
);


class Animated_Icon : public Fl_Box {
public:
	Animated_Icon(int X, int Y, int W, int H, const char *L);
	~Animated_Icon();               // deletes the Fl_Pixmaps!

	void add(Fl_Pixmap *, float);   // add after current, make current
	void load_animated_gif(char*, float, uchar, uchar);  // load gif file

	void clear_animation();
	void start();                   // start continuous display
	void stop();
	int running() const { return running_; }

	void set(int, uchar);                   // change to this one, no update
			       			// user must call redraw()
        unsigned short maxframes;


private:
	struct icon_list {
		Fl_Pixmap *icon;        // pixmap to draw
		float delay;            // how long to leave it up
		icon_list *next;
	};

	icon_list *first;
	icon_list *current;
	int running_;

	struct data_list {
		char **data;        // data for pixmap
                int *linelength;
		data_list *nex;
	};

	data_list *fir;
	data_list *cur;

        FILE* GIFfile;

        char **dataglob;

        int *linelengthglob;

	int g_a_w, g_a_h, n_g_a_w, n_g_a_h;

	void mem_gif(float);

	static void icon_cb(Animated_Icon *);
};

#endif
