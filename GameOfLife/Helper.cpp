#include "Helper.h"

// Given the board, it prints the contents of the board in rows and columns.
// 'X' denotes a living cell, and '-' is an empty cell.
void Helper::printBoard(bool** board, unsigned short rows, unsigned short cols)
{
    for (unsigned short i = 0; i < rows; ++i) 
    {
        for (unsigned short j = 0; j < cols; ++j) 
        {
            if (board[i][j] == 0)
            {
                std::cout << "- ";
            }
            else
            {
                std::cout << "X ";
            }
        }

        std::cout << std::endl;
    }
}

// Given the board, deletes the memory allocated for the 2D array when cleanup occurs.
void Helper::deleteBoard(bool**& board, unsigned short row)
{
    // Free the memory after the use of array
    for (unsigned short i = 0; i < row; ++i) 
    {
        delete[] board[i];
    }
    delete[] board;
}

// Copy the contents from a 2D board to another board
void Helper::copyBoard(bool** src, bool**& dest, unsigned short rows, unsigned short cols)
{
    // Allocate memory for the destination array
    dest = new bool*[rows];
    for (unsigned short i = 0; i < rows; ++i) {
        dest[i] = new bool[cols];
        for (unsigned short j = 0; j < cols; ++j) {
            // Copy each element from the source to the destination
            dest[i][j] = src[i][j];
        }
    }
}

// Given the board, it prints the contents of the board in rows and columns.
// 'X' denotes a living cell, and '-' is an empty cell.
// Returns a string instead of printing to console.
std::string Helper::printBoardToString(bool** board, unsigned short rows, unsigned short cols)
{
    std::string output = "";
    for (unsigned short i = 0; i < rows; ++i) 
    {
        for (unsigned short j = 0; j < cols; ++j) 
        {
            if (board[i][j] == 0)
            {
                output += "- ";
            }
            else
            {
                output += "X ";
            }
        }

        output += "\n";
    }

    return output;
}

// Generates the output file name that includes the date and time
std::string Helper::generateFileName()
{
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Extract year, month, day, hour, and minute
    int year = localTime->tm_year + 1900;  // tm_year is years since 1900
    int month = localTime->tm_mon + 1;     // tm_mon is months since January (0-11)
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour - 1;
    int minute = localTime->tm_min;

    // Construct the filename manually
    std::string fileName = "output_" +
                           std::to_string(year) +
                           (month < 10 ? "0" : "") + std::to_string(month) +
                           (day < 10 ? "0" : "") + std::to_string(day) +
                           "_" +
                           (hour < 10 ? "0" : "") + std::to_string(hour) +
                           (minute < 10 ? "0" : "") + std::to_string(minute) +
                           ".txt";

    return fileName;
}

// Check to see if the cell is on the corner of the board
bool Helper::isCorner(unsigned short boardRows, unsigned short boardCols, short currRow, unsigned short currCol)
{
    if (currRow == 0 && currCol == 0) // top left
        return true;
    else if (currRow == boardRows-1 && currCol == 0) // bottom left
        return true;
    else if (currRow == 0 && currCol == boardCols-1) // top right
        return true;
    else if (currRow == boardRows-1 && currCol == boardCols-1) // bottom right
        return true;
    else
        return false;
}

// Check to see if the cell is on the edges of the board
bool Helper::isEdge(unsigned short boardRows, unsigned short boardCols, short currRow, unsigned short currCol)
{
    if (currRow == 0 || currRow == boardRows-1) // top or bottom edge
        return true;
    else if (currCol == 0 || currCol == boardCols-1) // left or right edge
        return true;
    else
        return false;
}

// Check to see if the board has any cells existing.
bool Helper::checkEmpty(bool** board, unsigned short rows, unsigned short cols)
{
    for (unsigned short i = 0; i < rows; ++i) 
    {
        for (unsigned short j = 0; j < cols; ++j)
        {
            if (board[i][j] == 1) return false;
        }
    }

    return true;
}

// Compare the two generations (current and next) to see if they are the same. If they are, it is stabalized.
bool Helper::checkStabalized(bool** currBoard, bool** nextBoard, unsigned short rows, unsigned short cols)
{
    for (unsigned short i = 0; i < rows; ++i)
    {
        for (unsigned short j = 0; j < cols; ++j)
        {
            if (currBoard[i][j] != nextBoard[i][j]) return false;
        }
    }

    return true;
}

// The logic on determining if a cell lives or dies in the next generation.
void Helper::cellsNextGeneration(bool** currGenBoard, bool**& nextGenBoard, unsigned short currRow, unsigned short currCol, unsigned short neighbors)
{
    if (neighbors <= 1 || neighbors >= 4) // cell dies
    {
        nextGenBoard[currRow][currCol] = 0;
    }
    else if (neighbors == 2) // cell remains stable
    {
        nextGenBoard[currRow][currCol] = currGenBoard[currRow][currCol];
    }
    else if (neighbors == 3) // cell is born
    {
        nextGenBoard[currRow][currCol] = 1;
    }
}
