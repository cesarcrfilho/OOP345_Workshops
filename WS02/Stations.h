/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 22 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 02 - Stations.h
---------------------------------------------------------------*/

#ifndef SICT_STATIONS_H__
#define SICT_STATIONS_H__
#include "Station.h"

namespace w2 {

    const int MAX_SIZE = 1024; // max size for char arrays

    /////////////////////////////////////////////////////////////////
    //                  Class Stations Declaration                 //
    /////////////////////////////////////////////////////////////////
    class Stations {
    private:
		char m_fileName[MAX_SIZE];
        unsigned m_numberOfStations;
        Station* m_stations;
    public:
        // constructors
        Stations();
        Stations(char* fileName);

        // destructor
        virtual ~Stations();

        // member functions
        void update() const;
        void restock() const;
        void report() const;
    };

}
#endif // !SICT_STATIONS_H__

