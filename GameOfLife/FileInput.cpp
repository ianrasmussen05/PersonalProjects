#include "FileInput.h"

FileInput::FileInput(std::string fileName)
{
    inFile = new std::ifstream(fileName);
    openFile();
}

FileInput::~FileInput()
{
    delete inFile;
}

// Open the file that was inputted by the user. Prompts user to re-enter a file if it does not exist.
void FileInput::openFile()
{
    while (true)
    {
        // Check if the file is successfully opened
        if (!inFile->is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            std::cout << "Enter a valid file: ";

            std::string fileName;
            std::cin >> fileName;

            inFile = new std::ifstream(fileName);

            continue;
        }
        
        break;
    }
}

// Based on the contents of the file, this method will create the board.
void FileInput::createBoard(bool**& board, unsigned short& row, unsigned short& col)
{
    // String variable to store the read data
    std::string s;

    unsigned short lineNum = 1;
    unsigned short currCol = 0;

    while (std::getline(*inFile, s))
    {
        if (lineNum == 1) 
        {
            row = std::stoi(s);
        }
        else if (lineNum == 2)
        {
            col = std::stoi(s);
            generateBoard(board, row, col);
        }
        else
        {
            bool* arrRow = getRow(col, s);
            for (unsigned short i = 0; i < col; ++i)
            {
                board[currCol][i] = arrRow[i];
            }

            currCol++;
        }

        lineNum++;
    }

    // Close the file
    inFile->close();
}

// Allocate memory for the board.
void FileInput::generateBoard(bool**& board, unsigned short row, unsigned short col)
{
    board = new bool*[row];
    for (unsigned short i = 0; i < row; ++i) 
    {
        board[i] = new bool[col]{false};
    }
}

// Helper function when reading from a file to get the contents of a row to store to board memory.
bool* FileInput::getRow(unsigned short size, std::string rowStr)
{
    bool* row = new bool[size];
    
    for (unsigned short i = 0; i < size; ++i)
    {
        if (rowStr[i] == '-')
            row[i] = 0;
        else 
            row[i] = 1;
    }

    return row;
}
