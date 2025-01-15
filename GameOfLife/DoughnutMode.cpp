#include "DoughnutMode.h"

DoughnutMode::DoughnutMode(bool** board, unsigned short row, unsigned short col)
{
    // Assign rows and columns
    this->row = row;
    this->col = col;

    // Initialize and copy generated board for generations
    Helper::copyBoard(board, currBoard, row, col);
    Helper::copyBoard(board, nextBoard, row, col);
}

DoughnutMode::~DoughnutMode()
{
    Helper::deleteBoard(currBoard, row);
    Helper::deleteBoard(nextBoard, row);
}

// When the user chooses to step through each generation that is printed to console.
int DoughnutMode::simulateEachStep()
{
    std::cout << std::endl;
    std::cout << "------------ Doughnut Mode ------------" << std::endl;

    unsigned int generations = 0;
    std::cout << "------------ Generation " << std::to_string(generations++) << " ------------" << std::endl;
    Helper::printBoard(nextBoard, row, col);

    while (true)
    {
        if (Helper::checkEmpty(currBoard, row, col))
        {
            std::cout << std::endl;
            std::cout << "World is empty!" << std::endl;

            std::cout << "Press 'Enter' to exit the program." << std::endl;
            std::string input;
            std::getline(std::cin, input);
            break;
        }

        std::cout << "Press 'Enter' key to generate next generation." << std::endl;
        std::string input;
        std::getline(std::cin, input);

        // Check if the user wants to exit
        if (input == "exit") {
            std::cout << "Exiting the loop." << std::endl;
            break;
        }

        // assign the next generation by the amount of neighbors per cell
        for (unsigned short i = 0; i < row; ++i)
        {
            for (unsigned short j = 0; j < col; ++j)
            {
                unsigned short neighbors = getNeighbors(i, j);
                //std::cout << "Row: " << std::to_string(i) << ", Column: " << std::to_string(j) << ". Has " << std::to_string(neighbors) << " neighbors." << std::endl;
                Helper::cellsNextGeneration(currBoard, nextBoard, i, j, neighbors);
            }
        }

        if (Helper::checkStabalized(currBoard, nextBoard, row, col))
        {
            std::cout << "Stabalized cells!" << std::endl;

            std::cout << "Press 'Enter' to exit the program." << std::endl;
            std::string input;
            std::getline(std::cin, input);
            break;
        }

        std::cout << "------------ Generation " << std::to_string(generations++) << " ------------" << std::endl;
        Helper::printBoard(nextBoard, row, col);

        // copy the new generation of the life to the current
        Helper::copyBoard(nextBoard, currBoard, row, col);
    }

    return 0;
}

// When the user chooses to not step through each generation, they print out the contents to a file
int DoughnutMode::stimulateToFile()
{
    std::string fileName = Helper::generateFileName();
    FileOutput* outFile = new FileOutput(fileName);

    outFile->writeToFile("------------ Doughnut Mode ------------");

    unsigned int generations = 0;
    outFile->writeToFile("------------ Generation " + std::to_string(generations++) + " ------------");
    std::string boardStr = Helper::printBoardToString(currBoard, row, col);
    outFile->writeToFile(boardStr);
    
    while (true)
    {
        if (Helper::checkEmpty(currBoard, row, col))
        {
            outFile->writeToFile("");
            outFile->writeToFile("World is empty!");
            break;
        }

        // assign the next generation by the amount of neighbors per cell
        for (unsigned short i = 0; i < row; ++i)
        {
            for (unsigned short j = 0; j < col; ++j)
            {
                unsigned short neighbors = getNeighbors(i, j);
                //std::cout << "Row: " << std::to_string(i) << ", Column: " << std::to_string(j) << ". Has " << std::to_string(neighbors) << " neighbors." << std::endl;
                Helper::cellsNextGeneration(currBoard, nextBoard, i, j, neighbors);
            }
        }

        if (Helper::checkStabalized(currBoard, nextBoard, row, col))
        {
            outFile->writeToFile("");
            outFile->writeToFile("Stabalized cells!");
            break;
        }


        outFile->writeToFile("------------ Generation " + std::to_string(generations++) + " ------------");
        std::string boardStr = Helper::printBoardToString(nextBoard, row, col);
        outFile->writeToFile(boardStr);

        // copy the new generation of the life to the current
        Helper::copyBoard(nextBoard, currBoard, row, col);
    }

    delete outFile;

    std::cout << "Contents have been written to " << fileName << std::endl;
    std::cout << std::endl;

    std::cout << "Press 'Enter' to exit the program." << std::endl;
    std::string input;
    std::getline(std::cin, input);

    return 0;
}

// Given the row and column of the cell, return the number of neighbors that contain a cell.
unsigned short DoughnutMode::getNeighbors(unsigned short currRow, unsigned short currCol)
{
    if (Helper::isCorner(this->row, this->col, currRow, currCol))
    {
        return getNeighborsFromCorner(currRow, currCol);
    }
    else if (Helper::isEdge(this->row, this->col, currRow, currCol))
    {
        return getNeighborsFromEdge(currRow, currCol);
    }
    else 
    {
        return getNeighborsFromOtherCells(currRow, currCol);
    }
}

// Get the number of neighbors from the corner of the board.
unsigned short DoughnutMode::getNeighborsFromCorner(unsigned short currRow, unsigned short currCol)
{
    unsigned short neighbors = 0;

    // check if the current cell is on the corners
    if (currRow == 0 && currCol == 0) // top left
    {
        if (currBoard[currRow][currCol+1] == 1) // right cell
            neighbors++;
        if (currBoard[currRow+1][currCol+1] == 1) // bottom right cell
            neighbors++;
        if (currBoard[currRow+1][currCol] == 1) // bottom cell
            neighbors++;
        if (currBoard[currRow][col-1] == 1) // doughnut right side
            neighbors++;
        if (currBoard[currRow+1][col-1] == 1) // doughnut right bottom
            neighbors++;
        if (currBoard[row-1][currCol] == 1) // doughnut bottom
            neighbors++;
        if (currBoard[row-1][currCol+1] == 1) // doughnut bottom right
            neighbors++;
        if (currBoard[row-1][col-1] == 1)
            neighbors++;
    }
    else if (currRow == row-1 && currCol == 0) // bottom left
    {
        if (currBoard[currRow][currCol+1] == 1) // right cell
            neighbors++;
        if (currBoard[currRow-1][currCol+1] == 1) // top right cell
            neighbors++;
        if (currBoard[currRow-1][currCol] == 1) // top cell
            neighbors++;
        if (currBoard[0][0] == 1)
            neighbors++;
        if (currBoard[0][1] == 1)
            neighbors++;
        if (currBoard[row-1][col-1] == 1)
            neighbors++;
        if (currBoard[row-2][col-1] == 1)
            neighbors++;
        if (currBoard[0][col-1] == 1)
            neighbors++;
    }
    else if (currRow == 0 && currCol == col-1) // top right
    {
        if (currBoard[currRow][currCol-1] == 1) // left cell
            neighbors++;
        if (currBoard[currRow+1][currCol-1] == 1) // bottom left cell
            neighbors++;
        if (currBoard[currRow+1][currCol] == 1) // bottom cell
            neighbors++;
        if (currBoard[0][0] == 1)
            neighbors++;
        if (currBoard[1][0] == 1)
            neighbors++;
        if (currBoard[row-1][col-1] == 1)
            neighbors++;
        if (currBoard[row-1][col-2] == 1)
            neighbors++;
        if (currBoard[row-1][0] == 1)
            neighbors++;
    }
    else if (currRow == row-1 && currCol == col-1) // bottom right
    {
        if (currBoard[currRow][currCol-1] == 1) // left cell
            neighbors++;
        if (currBoard[currRow-1][currCol-1] == 1) // top left cell
            neighbors++;
        if (currBoard[currRow-1][currCol] == 1) // top cell
            neighbors++;
        if (currBoard[row-1][0] == 1)
            neighbors++;
        if (currBoard[row-2][0] == 1)
            neighbors++;
        if (currBoard[0][col-1] == 1)
            neighbors++;
        if (currBoard[0][col-2] == 1)
            neighbors++;
        if (currBoard[0][0] == 1)
            neighbors++;
    }

    return neighbors;
}

// Get the number of neighbors from the edge of the board. Cannot be a corner.
unsigned short DoughnutMode::getNeighborsFromEdge(unsigned short currRow, unsigned short currCol)
{
    unsigned short neighbors = 0;

    // check if the current cell is on the edges of the board AND not the corners
    if (currRow == 0) // top row
    {
        if (currBoard[currRow][currCol-1] == 1) // left cell
            neighbors++;
        if (currBoard[currRow+1][currCol-1] == 1) // bottom left cell
            neighbors++;
        if (currBoard[currRow+1][currCol] == 1) // bottom cell
            neighbors++;
        if (currBoard[currRow+1][currCol+1] == 1) // bottom right cell
            neighbors++;
        if (currBoard[currRow][currCol+1] == 1) // right cell
            neighbors++;
        if (currBoard[row-1][currCol-1] == 1)
            neighbors++;
        if (currBoard[row-1][currCol] == 1)
            neighbors++;
        if (currBoard[row-1][currCol+1] == 1)
            neighbors++;
    }
    else if (currRow == row-1) // bottom row
    {
        if (currBoard[currRow][currCol-1] == 1) // left cell
            neighbors++;
        if (currBoard[currRow-1][currCol-1] == 1) // top left cell
            neighbors++;
        if (currBoard[currRow-1][currCol] == 1) // top cell
            neighbors++;
        if (currBoard[currRow-1][currCol+1] == 1) // top right cell
            neighbors++;
        if (currBoard[currRow][currCol+1] == 1) // right cell
            neighbors++;
        if (currBoard[0][currCol-1] == 1) 
            neighbors++;
        if (currBoard[0][currCol] == 1) 
            neighbors++;
        if (currBoard[0][currCol+1] == 1)
            neighbors++;
    }
    else if (currCol == 0) // left column
    {
        if (currBoard[currRow-1][currCol] == 1) // top cell
            neighbors++;
        if (currBoard[currRow-1][currCol+1] == 1) // top right cell
            neighbors++;
        if (currBoard[currRow][currCol+1] == 1) // right cell
            neighbors++;
        if (currBoard[currRow+1][currCol+1] == 1) // bottom right cell
            neighbors++;
        if (currBoard[currRow+1][currCol] == 1) // bottom cell
            neighbors++;
        if (currBoard[currRow-1][col-1] == 1)
            neighbors++;
        if (currBoard[currRow][col-1] == 1)
            neighbors++;
        if (currBoard[currRow+1][col-1] == 1)
            neighbors++;
    }
    else if (currCol == col-1) // right column
    {
        if (currBoard[currRow-1][currCol] == 1) // top cell
            neighbors++;
        if (currBoard[currRow-1][currCol-1] == 1) // top left cell
            neighbors++;
        if (currBoard[currRow][currCol-1] == 1) // left cell
            neighbors++;
        if (currBoard[currRow+1][currCol-1] == 1) // bottom left cell
            neighbors++;
        if (currBoard[currRow+1][currCol] == 1) // bottom cell
            neighbors++;
        if (currBoard[currRow-1][0] == 1)
            neighbors++;
        if (currBoard[currRow][0] == 1)
            neighbors++;
        if (currBoard[currRow+1][0] == 1)
            neighbors++;
    }

    return neighbors;
}

// Get the number of neighbors from the cell of the board. Cannot be an edge or corner.
unsigned short DoughnutMode::getNeighborsFromOtherCells(unsigned short currRow, unsigned short currCol)
{
    unsigned short neighbors = 0;

    // The current cell is not on an edge or corner
    if (currBoard[currRow][currCol-1] == 1) // left cell
        neighbors++;
    if (currBoard[currRow-1][currCol-1] == 1) // top left cell
        neighbors++;
    if (currBoard[currRow-1][currCol] == 1) // top cell
        neighbors++;
    if (currBoard[currRow-1][currCol+1] == 1) // top right cell
        neighbors++;
    if (currBoard[currRow][currCol+1] == 1) // right cell
        neighbors++;
    if (currBoard[currRow+1][currCol+1] == 1) // bottom right cell
        neighbors++;
    if (currBoard[currRow+1][currCol] == 1) // bottom cell
        neighbors++;
    if (currBoard[currRow+1][currCol-1] == 1) // bottom left cell
        neighbors++;

    return neighbors;
}
