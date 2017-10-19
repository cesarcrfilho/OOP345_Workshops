/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 18 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 06 - Grades.cpp
---------------------------------------------------------------*/

#include "Grades.h"
#include <fstream>

// char* constructor
// receives a C-style string with the name of
// the file holding the grade information for
// all students in a course
Grades::Grades(const char* fileName) {
    // creates the file object
    std::ifstream file(fileName);

    try {
        // checks if the file is opened
        if (file.is_open()) {

            // counts the number of records in the file
            size_t tmpCounter = 0;
            std::string buffer;
            while (std::getline(file, buffer)) tmpCounter++; // using getline to move the file pointer

            // rewind
            file.clear();
            file.seekg(0, file.beg);

            // allocates memory for the data member
            m_student = new Student[m_size = tmpCounter];

            // fills the array with student info
            while (file.good()) {
                static size_t i = 0;
                file >> m_student[i].studentId;
                file >> m_student[i].grade;
                i++;
            }
            file.close();
        }
        // if the file can't be opened, throw exception
        else {
            throw "Couldn't open the file";
        }
    }
    // catches the exception and display friendly message
    catch (const char* message) {
        std::cout << "An error occurred: " << message << std::endl;
    }
}

// destructor
Grades::~Grades() {
	// deallocates memory
	delete[] m_student;
}

// size
// returns the array size
size_t Grades::size() const { return m_size; }

// displayGrades
// receives a reference to the output stream object and
// the expression to be used in determining the letter grade
void Grades::displayGrades(std::ostream& ost, std::string(*functionPointer)(double)) const {
    // sets the precision for ostream
    ost.setf(std::ios::fixed);
    ost.precision(2);

    // for each element, print one record
    // pattern: StudentID Grade Letter
    for (size_t i = 0; i < size(); i++) {
        ost << m_student[i].studentId << ' ' << m_student[i].grade << ' ' << functionPointer(m_student[i].grade) << std::endl;
    }
}