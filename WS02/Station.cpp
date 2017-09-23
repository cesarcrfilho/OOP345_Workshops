/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 22 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 02 - Station.cpp
---------------------------------------------------------------*/

#include "Station.h"

namespace w2 {

    // counter declaration
    int Station::counter = 0;

    void Station::set(const std::string& name, unsigned studentPasses, unsigned adultPasses) {
        m_name = name;
        m_studentPasses = studentPasses;
        m_adultPasses = adultPasses;

        // increment the number of stations
        counter++;
    }

    void Station::update(PassType pass, int amount) {
        int tmpAmount = 0;

        if (pass == STUDENT) {
            tmpAmount = m_studentPasses + amount;
            m_studentPasses = tmpAmount < 0 ? 0 : tmpAmount;
        }
        else if (pass == ADULT) {
            tmpAmount = m_adultPasses + amount;
            m_adultPasses = tmpAmount < 0 ? 0 : tmpAmount;
        }
    }

    unsigned Station::inStock(PassType pass) const {
        unsigned result;
        
        if (pass == STUDENT)
            result = m_studentPasses;
        else if (pass == ADULT)
            result = m_adultPasses;
        
        return result;
    }

    // getters
    // getName
    const std::string& Station::getName() const { return m_name; }
    // getCounter
    int Station::getCounter() const { return counter; }
}