/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 22 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 02 - Station.h
---------------------------------------------------------------*/

#ifndef SICT_STATION_H__
#define SICT_STATION_H__
#include <string>

namespace w2 {

    // enum PassType
    enum PassType {
        ADULT,
        STUDENT
    };

    /////////////////////////////////////////////////////////////////
    //                   Class Station Declaration                 //
    /////////////////////////////////////////////////////////////////
    class Station {
    private:
        std::string m_name;
        unsigned m_adultPasses;
        unsigned m_studentPasses;
    public:
        // count the number of stations created
        static int counter;

        // constructors
        // default with initialization list
        Station() : m_name(""), m_adultPasses(0), m_studentPasses(0) {};

        // member functions
        // set 
        void set(const std::string& name, unsigned adultPasses, unsigned studentPasses);
        // update
        void update(PassType pass, int amount);
        // inStock
        unsigned inStock(PassType pass) const;
        
        // getters
        // getName
        const std::string& getName() const;
        // getCounter
        int getCounter() const;

    };

}

#endif // !SICT_STATION_H__

