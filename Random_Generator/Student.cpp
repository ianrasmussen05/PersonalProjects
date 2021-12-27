#include "Student.h"

Student::Student()
{
    m_name = "";
    m_year = "";
    m_email = "";
    m_scrollNumber = "";
}

Student::Student(std::string name, std::string year, std::string email, std::string scrollNumber)
{
    this->setName(name);
    this->setYear(year);
    this->setEmail(email);
    this->setScrollNumber(scrollNumber);
}

Student::~Student()
{
    // Nothing so far
}

std::string Student::toString()
{
    std::string s = "\tName: " + this->getName() + "\n\tYear: " + this->getYear() + "\n\tEmail: " + this->getEmail() + "\n\tScroll Number: "
         + this->getScrollNumber();

    return s;
}

int Student::compareObj(const Student &stud)
{
    Student student = stud;
    std::string name = student.getName();
    std::string year = student.getYear();
    std::string email = student.getEmail();
    std::string scrollNumber = student.getScrollNumber();

    if (this->m_name != name)
    {
        return -1;
    }
    else if (this->m_year != year)
    {
        return -1;
    }
    else if (this->m_email != email)
    {
        return -1;
    }
    else if (this->m_scrollNumber != scrollNumber)
    {
        return -1;
    }

    return 0;
}

std::string Student::getName()
{
    return m_name;
}

std::string Student::getYear()
{
    return m_year;
}

std::string Student::getEmail()
{
    return m_email;
}

std::string Student::getScrollNumber()
{
    return m_scrollNumber;
}

void Student::setName(std::string name)
{
    m_name = name;
}

void Student::setYear(std::string year)
{
    m_year = year;
}

void Student::setEmail(std::string email)
{
    m_email = email;
}

void Student::setScrollNumber(std::string scrollNumber)
{
    m_scrollNumber = scrollNumber;
}