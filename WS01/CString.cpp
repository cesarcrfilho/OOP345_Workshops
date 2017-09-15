/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 12 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 01 - CString.cpp
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS // need to be defined first
#include <iostream>
#include <cstring>
#include "CString.h"

namespace w1 {

    // global variable holding the CString max characters
    extern int stringMaxCapacity;

    /////////////////////////////////////////////////////////////////
    //                Class CString Member Definition              //
    /////////////////////////////////////////////////////////////////

    // default constructor - safe state
    CString::CString()
        : M_CAPACITY{ 0 } {
        m_name = nullptr;
    }

    // constructor receives c-string and initializes capacity
    CString::CString(const char* name, const int capacity)
        : M_CAPACITY{ capacity } {
        m_name = new char[M_CAPACITY + 1];
        strncpy(m_name, name, M_CAPACITY + 1);
        m_name[M_CAPACITY] = char(0);
    }

    // destructor
    CString::~CString() {
        delete[] m_name;
    }

    // queries

    //display()
    std::ostream& CString::display(std::ostream& ost) const {
        ost << m_name;
        return ost;
    }

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // operation overloading
    // e.g. ostream << CString
    std::ostream& operator<<(std::ostream& ost, const CString& rhs) {
        // variable to count the executions
        static int counter = 0;
        ost << counter << ": ";
        rhs.display(ost);
        counter++;
        return ost;
    }

}