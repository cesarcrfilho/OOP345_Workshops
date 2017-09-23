/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Sep 22 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 02 - Stations.cpp
---------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Stations.h"

namespace w2 {

    // constructors
    Stations::Stations() {
        m_fileName[0] = char(0);
        m_numberOfStations = 0;
        m_stations = nullptr;
    }

    Stations::Stations(char* fileName) {
		strcpy(m_fileName, fileName);
        int noStations = 0;
        int amountAdult = 0;
        int amountStudent = 0;
        char delimeter = char(0);
        char buffer[MAX_SIZE];

        // open the file for reading mode
        std::ifstream file(m_fileName);

        // check if suceeded
        if (!file.is_open()) {
            std::cerr << "File is not opened" << std::endl;
        }
        else {
            // read first two positions to find the number of stations and delimeter
            file >> noStations;
            file >> delimeter;
            
            // allocate memory for stations
            m_stations = new Station[noStations];

            for (int i = 0; i < noStations && file.good(); i++) {
                // skip the break line (\n)
                file.ignore(1);
                // get the station name
                file.getline(buffer, MAX_SIZE, delimeter);
                // get the passes amounts
                file >> amountAdult;
                file >> amountStudent;
                
                // instantiate Station objects
                m_stations[i].set(buffer, amountAdult, amountStudent);
            }
			file.close();
        }
    }

    // destructor
    Stations::~Stations() {
        // create file for writing
        std::ofstream file(m_fileName);

		if (file.is_open()) {
			// add the first line - number of stations
			file << m_stations->getCounter() << ';' << std::endl;

			// loop for each Station instantiated
			for (int i = 0; i < m_stations->getCounter(); i++) {
				file << m_stations[i].getName() << ';' << m_stations[i].inStock(STUDENT) << ' ' << m_stations[i].inStock(ADULT) << std::endl;
		    }
			file.close();
		}
        delete[] m_stations;
    }

    // member functions
    void Stations::update() const {
        // user input variables
        int studentPasses = 0;
        int adultPasses = 0;

        // header
        std::cout << std::endl << "Passes Sold :" << std::endl;
        std::cout << "-------------" << std::endl;

        // for each station, receive the passes sold
        for (int i = 0; i < m_stations->getCounter(); i++) {
            std::cout << m_stations[i].getName() << std::endl;

            // user inputs students passes sold
            std::cout << " Student Passes sold : ";
            std::cin >> studentPasses;

            // user inputs adults passes sold
            std::cout << " Adult   Passes sold : ";
            std::cin >> adultPasses;

            // updates the station with the new data
            // negate the user input to become SOLD values (unary -)
            m_stations[i].update(ADULT, -adultPasses);
            m_stations[i].update(STUDENT, -studentPasses);
        }
        std::cout << std::endl;
    }

    void Stations::restock() const {
        // user input variables
        int studentPasses = 0;
        int adultPasses = 0;

        // header
        std::cout << "Passes Added :" << std::endl;
        std::cout << "--------------" << std::endl;

        // for each station, receive the passes added
        for (int i = 0; i < m_stations->getCounter(); i++) {
            std::cout << m_stations[i].getName() << std::endl;

            // user inputs students passes sold
            std::cout << " Student Passes added : ";
            std::cin >> studentPasses;

            // user inputs adults passes sold
            std::cout << " Adult   Passes added : ";
            std::cin >> adultPasses;

            // updates the station with the new data
            m_stations[i].update(ADULT, adultPasses);
            m_stations[i].update(STUDENT, studentPasses);
        }
        std::cout << std::endl;
    }
    void Stations::report() const {
        // header
        std::cout << "Passes in Stock : Student Adult" << std::endl;
        std::cout << "-------------------------------" << std::endl;

        // for each station, write the data in one line
        for (int i = 0; i < m_stations->getCounter(); i++) {
            std::cout << std::left << std::setw(19) << m_stations[i].getName() << std::setfill(' ');
            std::cout << std::right << std::setw(6) << m_stations[i].inStock(STUDENT) << std::setfill(' ');
            std::cout << std::right << std::setw(6) << m_stations[i].inStock(ADULT) << std::setfill(' ') << std::endl;
        }
        std::cout << std::endl;
    }

}