/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 12 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 01 - CString.h
---------------------------------------------------------------*/

#ifndef SICT_CSTRING_H__
#define SICT_CSTRING_H__
#include <iostream>
#include <cstring>

namespace w1 {

    class CString {
    private:
        const int M_CAPACITY; // holds the c-string max capacity
        char* m_name;
    public:
        // constructors
        CString();
        CString(const char* name);
        // destructor
        ~CString();

        // getters
        char* getName() const;

        // queries
        std::ostream& display(std::ostream& ost = std::cout) const;
    };

    // non-member functions
    // operator << overloading
    // CString << ostream
    std::ostream& operator<<(std::ostream& ost, const CString& rhs);


}

#endif // !SICT_CSTRING_H__

