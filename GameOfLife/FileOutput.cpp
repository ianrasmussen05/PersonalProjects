#include "FileOutput.h"

FileOutput::FileOutput(std::string fileName)
{
    outFile = new std::ofstream(fileName);
    openFile();
}

FileOutput::~FileOutput()
{
    outFile->close();
    delete outFile;
}

void FileOutput::openFile()
{
    while (true)
    {
        // Check if the file is successfully opened
        if (!outFile->is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            std::cout << "Enter a valid file: ";

            std::string fileName;
            std::cin >> fileName;

            outFile = new std::ofstream(fileName);

            continue;
        }
        
        break;
    }
}

void FileOutput::writeToFile(std::string content)
{
    *outFile << content << std::endl;
}
