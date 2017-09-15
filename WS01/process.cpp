/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 12 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 01 - process.cpp
---------------------------------------------------------------*/

#include <iostream>
#include "process.h"
#include "CString.h"

namespace w1 {

    // function process
    void process(const char* name, const int capacity) {
        CString processed(name, capacity);
        std::cout << processed << std::endl;
    }
}