#ifndef _FILEINPUT_H
#define _FILEINPUT_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class FileInput
{
    private:
        std::ifstream* inFile;

        void openFile();
        // int validateFile();
        void generateBoard(bool**& board, unsigned short row, unsigned short col);
        bool* getRow(unsigned short size, std::string rowStr);

    public:
        FileInput(std::string fileName);
        ~FileInput();

        void createBoard(bool**& board, unsigned short& row, unsigned short& col);
};

#endif