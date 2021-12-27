#include "Student.h"
#include "CSV_Reader.h"
#include "Randomize.h"

#include <iostream>

int main (int argc, char *argv[])
{
    if (argc == 2)
    {
        std::string fileName = argv[1];
        std::vector<Student> *studentList; 
        std::vector<Student> *finalList;
        int validate;

        CSVReader *reader = new CSVReader(fileName);


        std::vector<std::vector<std::string>> dataList = reader->getData();
        validate = reader->validateData(dataList);

        if (validate < 0)
        {
            std::cout << "There was an error in validating the data." << std::endl;
            return -1;
        }

        // Get the student list
        studentList = reader->getStudentList();

        Randomize *randGen = new Randomize(studentList);
        randGen->run();
        finalList = randGen->getFinalList();

        std::cout << std::endl;
        std::cout << "Your Students are:" << std::endl;
        reader->printData(finalList);



        reader = NULL;
        randGen = NULL;

        delete reader;
        delete randGen;
        delete finalList;
        delete studentList;
    }
    else 
    {
        std::cout << "\nError: Please enter the file name as the second argument in the console\n" << std::endl;

        return -1;
    }

    return 0;
}