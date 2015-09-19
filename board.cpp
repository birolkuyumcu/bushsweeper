#include "board.h"


Board::Board(int iw, int ih)
{
  w=iw;
  h=ih;
  cells=(int *)malloc(w*h*sizeof(int));
  srand(time(NULL));
}

void Board::Locate(int inBush)
{
  int n=0,i;
  nBush=inBush;
// clear board
  for(i=0;i<w*h;i++){
    cells[i]=0;
  }
// locate Bushs
  int max=w*h;

  do{
    i=rand()%max;
    if(cells[i]!=-1){
      cells[i]=-1;
      n++;
    }
  }while(n<nBush);

for(int x=0;x<w;x++)
  for(int y=0;y<h;y++)
    CalcValue(x,y);

  nCells=w*h;
  nSigned=0;

}

void Board::CalcValue(int x,int y)
{

 int v=0;
 if(isBush(x,y)) return;
 if(isBush(x-1,y-1)) v++;
 if(isBush(x-1,y)) v++;
 if(isBush(x-1,y+1)) v++;
 if(isBush(x,y-1)) v++;
 if(isBush(x,y+1)) v++;
 if(isBush(x+1,y-1)) v++;
 if(isBush(x+1, y)) v++;
 if(isBush(x+1,y+1)) v++;
 cells[x+w*y]=v;

}

void Board::SetValue(int x,int y,int v)
{
  cells[x+w*y]=v;
  if(v==-2) nCells--;
}

int Board::GetValue(int x,int y)
{

 return cells[x+w*y];

}
bool Board::isBush(int x, int y)
{
   if(x<0 || y<0||x==w||y==h) return false;
   if(cells[x+w*y]==-1)
    return true;
   else
    return false;

}


Board::~Board()
{
   free(cells);

}


