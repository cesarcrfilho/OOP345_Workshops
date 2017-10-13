/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 13 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 05 - Notifications.cpp
---------------------------------------------------------------*/

#include "Notifications.h"

namespace w5 {
    
    // default constructor - empty
    Notifications::Notifications() {
        // allocate enough storage
        m_messages.reserve(M_MAXSIZE);
    }

    // rule of five

    // copy constructor
    Notifications::Notifications(const Notifications& src) {
        *this = src;
    }

    // move constructor
    Notifications::Notifications(Notifications&& src) {
        *this = std::move(src);
        // clear source vector
        src.m_messages.clear();
    }

    // copy assignment operator
    Notifications& Notifications::operator=(const Notifications& rhs) {
        if (this != &rhs) {
            // clear local vector
            m_messages.clear();
            for (auto i = rhs.m_messages.begin(); i < rhs.m_messages.end(); i++) {
                m_messages.push_back(*i);
            }
        }
        return *this;
    }

    // move assignment operator
    Notifications& Notifications::operator=(Notifications&& rhs) {
        if (this != &rhs) {
            // clear local vector
            m_messages.clear();
            for (auto i = rhs.m_messages.begin(); i < rhs.m_messages.end(); i++) {
                m_messages.push_back(*i);
            }
            // clear the right hand side vector
            rhs.m_messages.clear();
        }
        return *this;
    }

    // destructor
    Notifications::~Notifications() {
        // destroys the message objects
        m_messages.clear();
    }


    // operator+= overloading
    // adds msg to the set
    // e.g. Notifications += Message
    void Notifications::operator+=(const Message& msg) {
        // checks if the vector is full
        if (m_messages.size() != m_messages.capacity()) {
            // inserts a message at the last position available
            m_messages.push_back(msg);
        }
    }

    // display
    // inserts the Message objects to the os output stream
    void Notifications::display(std::ostream& ost) const {
        // if the vector is not empty, insert the messages
        // to the output stream using display method from Message class
        if (!m_messages.empty()) {
            for (auto i = m_messages.begin(); i < m_messages.end(); i++)
                i->display(ost);
        }
    }
}