/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 18 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 06 - Grades.h
---------------------------------------------------------------*/

#ifndef GRADES_H__
#define GRADES_H__
#include <iostream>
#include <string>

// structure that holds student info
struct Student {
    unsigned int studentId;
    double grade;
};

class Grades {
private:
    Student* m_student = nullptr; // default values
    size_t m_size = 0;
    
    // size
    // returns the array size
    size_t size() const;

    // private default constructor
    // prohibits default instantiation ~ no sense since we're working with files
    Grades();
public:
    // char* constructor
    // receives a C-style string with the name of
    // the file holding the grade information for
    // all students in a course
    Grades(const char* fileName);

    // prohibits copying, moving or assigning of a Grades object
    Grades(const Grades& src) = delete; // copy constructor
    Grades(Grades&& src) = delete; // move constructor
    Grades& operator=(const Grades& rhs) = delete; // copy assignment
    Grades& operator=(Grades&& rhs) = delete; // move assignment

    // displayGrades
    // receives a reference to the output stream object and
    // the expression to be used in determining the letter grade
    void displayGrades(std::ostream& ost, std::string(*functionPointer)(double)) const;

    // destructor
    virtual ~Grades();
};

#endif // !GRADES_H__