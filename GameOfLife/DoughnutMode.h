#ifndef _DOUGHNUTMODE_H
#define _DOUGHNUTMODE_H

#include "Helper.h"
#include "FileOutput.h"

class DoughnutMode
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
        DoughnutMode(bool** board, unsigned short row, unsigned short col);
        ~DoughnutMode();

        int simulateEachStep();
        int stimulateToFile();
};

#endif