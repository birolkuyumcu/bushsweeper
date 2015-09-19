#ifndef BOARD_H
#define BOARD_H
#include <stdlib.h>
#include <time.h>

class Board
{
    public:
        Board(int iw, int ih);
        void Locate( int inBush);
        int GetValue(int x,int y);
        void SetValue(int x,int y,int v);
        virtual ~Board();
        int nCells;
        int nSigned;
    protected:
        int *cells;
        int w;
        int h;
        int nBush;
        void CalcValue(int x,int y);

        bool isBush(int x, int y);
    private:
};



#endif // BOARD_H
