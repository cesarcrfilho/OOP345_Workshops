/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 13 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 05 - Notifications.h
---------------------------------------------------------------*/

#ifndef W5_NOTIFICATIONS_H__
#define W5_NOTIFICATIONS_H__
#include <ostream>
#include "Message.h"

namespace w5 {

    /////////////////////////////////////////////////////////////////
    //                 Class Notifications Declaration             //
    /////////////////////////////////////////////////////////////////
    class Notifications {
    private:
        Message* m_messages[10];
    public:
        // default constructor
        Notifications();

        // rule of five
        Notifications(const Notifications& src);            // copy constructor
        Notifications(Notifications&& src);                 // move constructor
        Notifications& operator=(const Notifications& rhs); // copy assignment operator
        Notifications& operator=(Notifications&& rhs);      // move assignment operator
        virtual ~Notifications();                           // destructor

        // operator+= overloading
        // adds msg to the set
        void operator+=(const Message& msg);

        // display
        // inserts the Message objects to the os output stream
        void display(std::ostream& os) const;
    };
}

#endif // !W5_NOTIFICATIONS_H__