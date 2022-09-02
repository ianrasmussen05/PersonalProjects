#include "CSV_Reader.h"

CSVReader::~CSVReader()
{
    delete studentList;
}

std::vector<std::vector<std::string>> CSVReader::getData()
{
    std::ifstream inFS;
    inFS.open(this->fileName); // Open file
 
    // If the file is not open. Thus, does not exist.
    if (!inFS.is_open())
    {
        std::cout << "Error: Could not open '" << fileName << "'. Please enter an existing file." << std::endl;
        exit(0);
    }

    // Checks to see if the file inputted is a .csv file
    if (fileName.substr(fileName.length() - 4) != ".csv")
    {
        std::cout << "Please enter a .csv file." << std::endl;
        exit(0);
    }

    std::vector<std::vector<std::string>> dataList;
    std::string line = "";

    // Iterate through each line and split the content using delimeter
    while (getline(inFS, line))
    {
        std::vector<std::string> vec;
        std::string str = "";

        for (unsigned int i = 0; i <= line.size(); ++i)
        {
            if (i == line.size())
            {
                vec.push_back(str);
                str = "";
            }
            else if (line[i] != ',')
            {
                str.push_back(line[i]);
            }
            else // line[i] == ','
            {
                vec.push_back(str);
                str = "";
            }
        }
        //boost::algorithm::split(vec, line, boost::is_any_of(this->delimeter));
        dataList.push_back(vec);
        numOfStudents++;
    }

    // Close the File
    inFS.close();

    return dataList;
}

int CSVReader::validateData(std::vector<std::vector<std::string>> data)
{
    int j = 0;

    for (auto &vect : data)
    {
        Student stud = Student();

        int i = 0;

        for (auto &value : vect)
        {
            if (i == 0) // This is the name of the student
            {
                if (validateName(value))
                {
                    stud.setName(value);
                }
                else 
                {
                    return -1;
                }
            }
            else if (i == 1) // The year of the student
            {
                if (validateYear(value))
                {
                    stud.setYear(value);
                }
                else
                {
                    return -1;
                }
            }
            else if (i == 2) // The email of the student
            {
                if (validateEmail(value))
                {
                    stud.setEmail(value);
                }
                else 
                {
                    return -1;
                }
            }
            else // The scroll number of the student
            {
                if (validateNumber(value))
                {
                    stud.setScrollNumber(value);
                }
                else 
                {
                    return -1;
                }
            }

            i++;
        }

        studentList->push_back(stud);
        j++;
    }

    return 0;
}

bool CSVReader::validateName(std::string name)
{
    short spaceCounter = 0;
    for (unsigned int i = 0; i < name.size(); ++i)
    {
        if (name[i] == ' ')
        {
            spaceCounter++;
        }
        if (name[i] == '@' || name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$' || name[i] == '%' 
            || name[i] == '^' || name[i] == '&')
        {
            std::cout << "You have a symbol in the name: '" << name << "'." << std::endl;
            return false;
        }
    }

    if (spaceCounter < 1)
    {
        std::cout << "There is not a First and Last name in '" << name << "'." << std::endl;
        return false;
    }

    return true;
}

bool CSVReader::validateYear(std::string year)
{
    int yearNum = std::stoi(year);

    // Goes 30 years into the future
    if (yearNum < 2018 || yearNum > 2050)
    {
        std::cout << "The years must be between 2018 and 2050" << std::endl;
        return false;
    }

    return true;
}

bool CSVReader::validateEmail(std::string email)
{
    bool atSymbol = false;
    bool periodSymbol = false;
    short atCounter = 0;
    short periodCounter = 0;

    for (unsigned int i = 0; i < email.size(); ++i)
    {
        if (email[i] == '@')
        {
            atSymbol = true;
            atCounter++;
        }
        if (email[i] == '.')
        {
            periodSymbol = true;
            periodCounter++;
        }

        if ((periodSymbol == true && atSymbol == true) && (atCounter == 1 && periodCounter == 1))
        {
            return true;
        }
        // It is the end of the string and there was no '@' or '.' within the text.
        else if (i == email.size() && (periodSymbol == false || atSymbol == false))
        {
            std::cout << "The email '" << email << "' is not valid." << std::endl;
            return false;
        }
    }

    return true;
}

bool CSVReader::validateNumber(std::string scrollNumber)
{
    int scroll = std::stoi(scrollNumber);

    // Checks if the scroll is less than 0 or greater than 200
    if (scroll < 1 || scroll > 200)
    {
        std::cout << "The scroll number is incorrect (must be between 1-200)" << std::endl;
        return false;
    }

    return true;
}

void CSVReader::printData(std::vector<Student> *data)
{
    int counter = 1;
    for (auto &student : *data)
    {
        std::string studentOutput = student.toString();

        std::cout << "Student " << counter++ << "\n";
        std::cout << studentOutput << std::endl;
        std::cout << std::endl;
    }   
}

// Getters
std::vector<Student>* CSVReader::getStudentList()
{
    return studentList;
}