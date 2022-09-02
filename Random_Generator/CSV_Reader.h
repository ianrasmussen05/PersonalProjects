/*
 * Used this link: https://thispointer.com/how-to-read-data-from-a-csv-file-in-c/
 * To get both CSV_Reader.h and CSV_Reader.cpp
 * This allows me to read from a .csv file
*/

#ifndef _CSV_READER_H
#define _CSV_READER_H

#include "Student.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

/*
 * A class to read data from a csv file.
 */
class CSVReader
{
    public:
        // Constructors
        CSVReader()
        {
            numOfStudents = 0;
            fileName = "";
            delimeter = "";
            studentList = new std::vector<Student>();
        }
        CSVReader(std::string filename, std::string delm = ",") : fileName(filename), delimeter(delm) 
        {
            numOfStudents = 0;
            studentList = new std::vector<Student>();
        }
        ~CSVReader();

        // Member Functions
        std::vector<std::vector<std::string>> getData(); // Function to fetch data from a CSV File
        int validateData(std::vector<std::vector<std::string>> data);
        bool validateName(std::string name);
        bool validateYear(std::string year);
        bool validateEmail(std::string email);
        bool validateNumber(std::string scrollNumber);
        void printData(std::vector<Student> *data);

        // Getters
        std::vector<Student>* getStudentList();

        // Variables
        unsigned int numOfStudents;

    private:
        std::string fileName;
        std::string delimeter;
        const std::string symbols = "!@#$%^&*()_+-=<>/.?;:~`|";
        std::vector<Student> *studentList;
};

#endif