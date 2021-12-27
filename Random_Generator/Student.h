#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
#include <iostream>

class Student
{
    public:
        // Constructors
        Student();
        Student(std::string name, std::string year,std::string email, std::string scrollNumber);
        ~Student();

        std::string toString();
        int compareObj(const Student &stud);

        // Overloading Operators
        bool operator == (const Student &stud)
        {
            return (0 == compareObj(stud));
        }

        // Getters
        std::string getName();
        std::string getYear();
        std::string getEmail();
        std::string getScrollNumber();

        // Setters
        void setName(std::string name);
        void setYear(std::string year);
        void setEmail(std::string email);
        void setScrollNumber(std::string scrollNumber);

    private:
        std::string m_name;
        std::string m_year;
        std::string m_email;
        std::string m_scrollNumber;
};


#endif