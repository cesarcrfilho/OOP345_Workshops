/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 13 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 05 - Message.h
---------------------------------------------------------------*/

#ifndef W5_MESSAGE_H__
#define W5_MESSAGE_H__
#include <string>
#include <fstream>

namespace w5 {

    /////////////////////////////////////////////////////////////////
    //                    Class Message Declaration                //
    /////////////////////////////////////////////////////////////////
    class Message {
    private:
        std::string m_message;

        // parse
        // this function takes a string and a char delimeter
        // parses it, and inserts the result into m_message
        void parse(std::string buffer, char c);
    public:
        // default constructor
        Message();
        
        // constructor retrieves a record from the in file object, parses the record
        // and stores its components in the Message object.
        // c is the character that delimits each record
        Message(std::ifstream& in, char c);
        
        // empty
        // returns true if the object is in a safe empty state
        bool empty() const;

        // display
        // displays the Message objects within the container
        void display(std::ostream& ost) const;
    };

}

#endif // !W5_MESSAGE_H__

