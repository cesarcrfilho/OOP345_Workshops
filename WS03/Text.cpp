/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 29 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 03 - Text.cpp
---------------------------------------------------------------*/

#include <string>
#include <fstream>
#include "Text.h"

namespace w3 {
    
    /////////////////////////////////////////////////////////////////
    //                  Constructors and Destructor                //
    /////////////////////////////////////////////////////////////////

	// default constructor - safe empty state
	Text::Text() {
        set();
	}

    // string argument constructor
    Text::Text(const std::string& fileName) {
        std::ifstream file(m_fileName = fileName);
        std::string buffer = ""; // buffer to count lines
        m_noOfRecords = 0;

        if (file.is_open()) {
            // count the number of lines
            while (std::getline(file, buffer))
                m_noOfRecords++;

            // allocate memory
            m_records = new std::string[m_noOfRecords];

            // loop the records and save them to the obj
            for (size_t i = 0; i < m_noOfRecords; i++)
                file >> m_records[i];

            // close the file after read
            file.close();
        }
        // if the file is not opened, put the obj in safe empty state
        else
            set();
    }

	// copy constructor
	Text::Text(const Text& rhs) {
        m_fileName = rhs.m_fileName;
        
        // allocate memory
        m_records = new std::string[m_noOfRecords = rhs.m_noOfRecords];

        // copy records
        for (size_t i = 0; i < rhs.m_noOfRecords; i++)
            m_records[i] = rhs.m_records[i];
	}

	// move constructor
	Text::Text(Text&& rhs) _NOEXCEPT {
        m_fileName = rhs.m_fileName;
        
        // copy data pointer and length
        m_records = rhs.m_records;
        m_noOfRecords = rhs.m_noOfRecords;

        // copy records
        for (size_t i = 0; i < m_noOfRecords; i++)
            m_records[i] = rhs.m_records[i];
        
        // release pointer from right-hand side
        rhs.m_records = nullptr;

        // reset right-hand side to safe empty state
        rhs.set();
	}

    // destructor
    Text::~Text() {
        delete[] m_records;
    }

    /////////////////////////////////////////////////////////////////
    //                     Operator Overloading                    //
    /////////////////////////////////////////////////////////////////

	// copy assignment
	Text& Text::operator=(const Text& rhs) {
        if (this != &rhs) {
            m_fileName = rhs.m_fileName;
            
            // reallocate memory
            delete[] m_records;
            m_records = new std::string[m_noOfRecords = rhs.m_noOfRecords];

            // copy records
            for (size_t i = 0; i < rhs.m_noOfRecords; i++)
                m_records[i] = rhs.m_records[i];
        }
        return *this;
	}

	// move assignment
	Text& Text::operator=(Text&& rhs) _NOEXCEPT {
        if (this != &rhs) {
            m_fileName = rhs.m_fileName;

            // delete existing memory allocation
            delete[] m_records;

            // copy data pointer and length
            m_records = rhs.m_records;
            m_noOfRecords = rhs.m_noOfRecords;

            // copy records
            for (size_t i = 0; i < m_noOfRecords; i++)
                m_records[i] = rhs.m_records[i];

            // release pointer from right-hand side
            rhs.m_records = nullptr;

            // reset right-hand side to safe empty state
            rhs.set();
        }
        return *this;
	}

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // set()
    // sets the object to sate empty state
    void Text::set() {
        delete[] m_records;
        m_records = nullptr;
        m_fileName = "";
        m_noOfRecords = 0;
    }

	// size()
	// returns the number of records of text data
    size_t Text::size() const {
        return m_noOfRecords;
    }

}