#ifndef _HELPER_H
#define _HELPER_H

#include <iostream>
#include <string>
#include <ctime>

class Helper
{
    public:
        static void deleteBoard(bool**& board, unsigned short row);
        static void copyBoard(bool** src, bool**&, unsigned short rows, unsigned short cols);

        static void printBoard(bool** board, unsigned short rows, unsigned short cols);
        static std::string printBoardToString(bool** board, unsigned short rows, unsigned short cols);
        static std::string generateFileName();

        static bool isCorner(unsigned short boardRows, unsigned short boardCols, short currRow, unsigned short currCol);
        static bool isEdge(unsigned short boardRows, unsigned short boardCols, short currRow, unsigned short currCol);
        static bool checkEmpty(bool** board, unsigned short rows, unsigned short cols);
        static bool checkStabalized(bool** currBoard, bool** nextBoard, unsigned short rows, unsigned short cols);
        static void cellsNextGeneration(bool** currGenBoard, bool**& nextGenBoard, unsigned short currRow, unsigned short currCol, unsigned short neighbors);
};

#endif