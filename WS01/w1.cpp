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

/////////////////////////////////////////////////////////////////
//                         Main Function                       //
/////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {

    int stringMaxCapacity = 0; // will be user input
    int result = 0; // controls the execution success/failure

    // prints the arguments from the command line
    cout << "Command Line : ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i];
        // adds a space if it's not the last element
        if (i != argc - 1)
            cout << " ";
    }
    cout << endl;

    // if no arguments, failure
    if(argc <= 1) {
        cerr << "Insufficient number of arguments (min 1)" << endl;
        result = 1;
    } else {
        cout << "Maximum number of characters to be stored : ";
        cin >> stringMaxCapacity;

        // control user input - check cin and positive input
        while (cin.bad() || stringMaxCapacity <= 0) {
            cerr << "Please enter a valid positive number: ";
            cin >> stringMaxCapacity;
        }
        
        // run process function for all parameter
        for (int i = 1; i < argc; i++) {
            process(argv[i], stringMaxCapacity);
        }
     }
    return result;
}