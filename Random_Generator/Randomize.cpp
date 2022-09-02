#include "Randomize.h"

Randomize::Randomize()
{
    studentList = new std::vector<Student>();
    finalList = new std::vector<Student>();;
}

Randomize::Randomize(std::vector<Student> *studList)
{
    studentList = studList;
    finalList = new std::vector<Student>();
}

Randomize::~Randomize()
{
    delete studentList;
    delete finalList;
}

void Randomize::run()
{
    int userInput;
    int numOfStudents;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "\t1) Randomly select a Student\n\t2) Randomly select a Student by year\n\t3) Print all Students\n";
    std::cin >> userInput;
    std::cout << std::endl;

    if (userInput == 1 || userInput == 2)
    {
        std::cout << "How many students would you like to generate?" << std::endl;
        std::cin >> numOfStudents;
        std::cout << std::endl;

        if (numOfStudents < 1 || numOfStudents > (int)studentList->size())
        {
            std::cout << "The input is not valid. Must be between 1-" << studentList->size() << ".\n" << std::endl;
            exit(0);
        }

        // Need to come back and finish this!
        if (userInput == 1)
        {
            for (int i = 0; i < numOfStudents; ++i)
            {
                Student currStudent;
                currStudent = getRandomStudent();

                while (!checkRepeat(currStudent, finalList))
                {
                    currStudent = getRandomStudent();
                }


                finalList->push_back(currStudent);
            }
        }
        else // userInput == 2
        {
            std::vector<std::string> years = getValidYears();

            for (int i = 0; i < numOfStudents; ++i)
            {
                std::string year;
                std::cout << "What year would you like to randomize from?\nYour options are:" << std::endl;
                for (auto &str : years)
                {
                    std::cout << '\t' << str << '\n';
                }
                std::cin >> year;

                auto iterate = std::find(years.begin(), years.end(), year);

                while (iterate == years.end())
                {
                    std::cout << "Please enter a valid year: ";
                    std::cin >> year;
                    std::cout << std::endl;

                    iterate = std::find(years.begin(), years.end(), year);
                }


                Student currStudent;
                currStudent = getStudentByYear(year);

                while (!checkRepeat(currStudent, finalList))
                {
                    currStudent = getStudentByYear(year);
                }

                finalList->push_back(currStudent);
            }
        }
    }
    else if (userInput == 3)
    {
        int counter = 1;
        for (auto &student : *studentList)
        {
            std::string studentOutput = student.toString();

            std::cout << "Student " << counter++ << "\n";
            std::cout << studentOutput << std::endl;
            std::cout << std::endl;
        }   
        
        exit(0);
    }
    else 
    {
        std::cout << "The input is not valid...\n" << std::endl;
        exit(0);
    }
}

Student Randomize::getRandomStudent()
{
    Student stud = Student();

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(studentList->begin(), studentList->end(), std::default_random_engine(seed));
    stud = studentList->front();

    return stud;
}

Student Randomize::getStudentByYear(std::string year)
{
    Student stud = Student();
    std::vector<Student> list;

    for (auto &currStudent : *studentList)
    {
        if (currStudent.getYear() == year)
        {
            list.push_back(currStudent);
        }
    }

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(list.begin(), list.end(), std::default_random_engine(seed));
    stud = list.front();


    return stud;
}

bool Randomize::checkRepeat(Student stud, std::vector<Student> *list)
{
    for (auto &currStudent : *list)
    {
        if (currStudent == stud)
        {
            return false;
        }
    }

    return true;
}

std::vector<Student>* Randomize::getFinalList()
{
    return finalList;
}

std::vector<std::string> Randomize::getValidYears()
{
    std::vector<std::string> yearVector;
    for (auto &stud : *studentList)
    {
        yearVector.push_back(stud.getYear());
    }

    std::sort(yearVector.begin(), yearVector.end());
    yearVector.erase(std::unique(yearVector.begin(), yearVector.end()), yearVector.end());

    return yearVector;
}