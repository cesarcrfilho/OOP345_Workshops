/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 12 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 01 - tester.cpp
---------------------------------------------------------------*/

#include <iostream>
#include "CString.h"
#include "process.h"
using namespace std;
using namespace w1;

int main(int argc, char** argv) {

    int result = 0; // controls the execution success/failure
    
    // if no arguments, failure
    if(argc <= 0 || argc == NULL) {
        cout << "Insufficient number of arguments (min 1)" << endl;
        result = 1;
    } else {
        cout << "Maximum number of characters stored : 3" << endl;
        
        // run process function for all parameter
        for (int i = 1; i < argc; i++) {
            process(argv[i]);
        }
    }

    return result;
}