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

    /////////////////////////////////////////////////////////////////
    //                   Class CString Declaration                 //
    /////////////////////////////////////////////////////////////////
    
    class CString {
    private:
        const int M_CAPACITY; // holds the c-string max capacity
        char* m_name;
    public:
        // constructors
        CString();
        CString(const char* name, const int capacity);
        // destructor
        ~CString();

        // queries
        std::ostream& display(std::ostream& ost = std::cout) const;
    };

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // operator<< overloading
    // e.g. ostream << CString
    std::ostream& operator<<(std::ostream& ost, const CString& rhs);

}

#endif // !SICT_CSTRING_H__

