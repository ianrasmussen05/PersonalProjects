#ifndef _RANDOMIZE_H
#define _RANDOMIZE_H

#include "Student.h"
#include "CSV_Reader.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

class Randomize 
{
    public: 
        // Constructors
        Randomize();
        Randomize(std::vector<Student> *studList);
        ~Randomize();

        // Functions
        void run();
        Student getRandomStudent();
        Student getStudentByYear(std::string year);
        bool checkRepeat(Student stud, std::vector<Student> *list);

        // Getter
        std::vector<Student>* getFinalList();
        std::vector<std::string> getValidYears();

    private:
        std::vector<Student> *studentList;
        std::vector<Student> *finalList;
};

#endif