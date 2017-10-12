/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 13 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 05 - Message.cpp
---------------------------------------------------------------*/

#include <string>
#include "Message.h"

namespace w5 {

    // default constructor
    Message::Message() {
        // safe empty state
        m_message.clear();
    }

    // constructor retrieves a record from the in file object, parses the record
    // and stores its components in the Message object.
    // c is the character that delimits each record
    Message::Message(std::ifstream& in, char c) {
        std::string buffer;

        if (in.is_open()) {
            std::getline(in, buffer, c);

            // parses the data
            parse(buffer, c);

        }
    }

    // empty
    // returns true if the object is in a safe empty state
    bool Message::empty() const { return m_message.empty(); }

    // display
    // displays the Message objects within the container
    void Message::display(std::ostream& ost) const {
        if (!empty()) {
            ost << "Message" << std::endl;
            ost << m_message << std::endl;
        }
        else {
            ost << "This object is empty" << std::endl;
        }
    }

    // parse
    // this function takes a string and a char delimeter
    // parses it, and inserts the result into m_message
    void Message::parse(std::string buffer, char c) {
        // variables to hold the parsed data
        std::string user;
        std::string replyName;
        std::string tweet;

        size_t found = 0; // holds the position of the last found char

        // constants to hold the character values
        const char at = '@';
        const char blank = ' ';

        if (!buffer.empty()) {
            // to get the user
            // find the first blank space to get the user
            // fill found variable with ending position of user
            user = buffer.substr(0, found = buffer.find(blank));
            // erase the user from the buffer
            buffer.erase(0, found + 1);

            // npos means no match
            // check if there's an @ sign
            if (buffer.find(at) != std::string::npos) {
                // to get the reply name
                // find the first @ and get the string until the following blank space
                replyName = buffer.substr(buffer.find(at), found = buffer.find(blank));

                // remove the reply name from the buffer
                buffer.erase(0, found + 1);
            }

            if (found != std::string::npos) {
                // to get the tweet
                // get the remaining string from the buffer
                tweet = buffer.substr(0);
            }

            // if the data is valid
            // must contain at least user and message/tweet
            if (!user.empty() && !tweet.empty()) {
                // concatenate all data
                m_message = "User : " + user + c;
                if (!replyName.empty())
                    m_message += "Reply : " + replyName + c;
                m_message += "Message : " + tweet;

            }
        }
    }

}