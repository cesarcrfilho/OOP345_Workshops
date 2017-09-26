/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 26 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 03 - Text.h
---------------------------------------------------------------*/

#ifndef SICT_TEXT_H__
#define SICT_TEXT_H__

#include <string>

namespace w3 {

    /////////////////////////////////////////////////////////////////
    //                     Class Text Declaration                  //
    /////////////////////////////////////////////////////////////////
	class Text {
	private:
		std::string* m_records = nullptr;
        size_t m_noOfRecords;
        std::string m_fileName;

        // set()
        // sets the object to sate empty state
        void set();
	public:
		// constructors
		Text();
		Text(const std::string& fileName);

		Text(const Text& rhs); // copy constructor
		Text(Text&& rhs); // move constructor
		Text& operator=(const Text& rhs); // copy assignment
		Text& operator=(Text&& rhs); // move assignment

		// destructor
		virtual ~Text();

		// size()
		// returns the number of records of text data
		size_t size() const;
	};

}
#endif // !SICT_TEXT_H__