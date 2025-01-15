#ifndef _USERINPUT_H
#define _USERINPUT_H

#include "FileInput.h"
#include "Helper.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

#include <exception>

class UserInput
{
    private:
        bool** board;
        unsigned short row;
        unsigned short col;
        float density;

        // Getting User inputs
        void getRandomizeInput();
        void getFileInput();

        // Generating boards
        void generateBoard(bool**& arr, unsigned short row, unsigned short col);
        void randomizeBoard(bool**& arr, float density);

        // Generating modes
        void generateClassicMode(bool generationMode);
        void generateDoughnutMode(bool generationMode);
        void generateMirrorMode(bool generationMode);

        // Helpers
        unsigned short validateShort(std::string message);
        float validateFloat(std::string message, float& min, float& max);

    public:
        UserInput();
        UserInput(unsigned short row, unsigned short col, float density);
        ~UserInput();

        // Getters
        bool** getBoard();
        unsigned short getRow();
        unsigned short getCol();
        float getDensity();

        // Setters
        void setRow(unsigned short row);
        void setCol(unsigned short col);
        void setDensity(float density);

        void getUserInput();
};

#endif