#ifndef _MIRRORMODE_H
#define _MIRRORMODE_H

#include "Helper.h"
#include "FileOutput.h"

class MirrorMode
{
    private:
        bool** currBoard;
        bool** nextBoard;
        unsigned short row;
        unsigned short col;

        unsigned short getNeighbors(unsigned short currRow, unsigned short currCol);
        unsigned short getNeighborsFromCorner(unsigned short currRow, unsigned short currCol);
        unsigned short getNeighborsFromEdge(unsigned short currRow, unsigned short currCol);
        unsigned short getNeighborsFromOtherCells(unsigned short currRow, unsigned short currCol);

    public:
        MirrorMode(bool** board, unsigned short row, unsigned short col);
        ~MirrorMode();

        int simulateEachStep();
        int stimulateToFile();
};

#endif