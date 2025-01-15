#ifndef _FILEOUTPUT_H
#define _FILEOUTPUT_H

#include <fstream>
#include <iostream>
#include <string>

class FileOutput
{
    private:
        std::ofstream* outFile;

        void openFile();

    public:
        FileOutput(std::string fileName);
        ~FileOutput();

        void writeToFile(std::string content);
};

#endif