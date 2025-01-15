#ifndef _CLASSICMODE_H
#define _CLASSICMODE_H

#include "Helper.h"
#include "FileOutput.h"

class ClassicMode
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
        ClassicMode(bool** board, unsigned short row, unsigned short col);
        ~ClassicMode();

        int simulateEachStep();
        int stimulateToFile();
};

#endif