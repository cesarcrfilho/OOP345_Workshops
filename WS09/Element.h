/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Dec 14 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 09 - Element.h
---------------------------------------------------------------*/

// Workshop 9 - Smart Pointers
// Element.h
// cda-conceicao-rodrig - 14/DEC/2017 - begin
#ifndef W9_ELEMENT_H__
#define W9_ELEMENT_H__
// cda-conceicao-rodrig - 14/DEC/2017 - end

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w9 {

    struct Description {
        unsigned code;
        std::string desc;
        bool load(std::ifstream& f) {
            f >> code >> desc;
            return f.good();
        }
        void display(std::ostream& os) const {
            os << std::setw(FWC) << code << std::setw(FWD)
                << desc << std::endl;
        }
    };

    struct Price {
        unsigned code;
        double price;
        bool load(std::ifstream& f) {
            f >> code >> price;
            return f.good();
        }
        void display(std::ostream& os) const {
            os << std::setw(FWC) << code << std::setw(FWP)
                << price << std::endl;
        }
    };

    struct Product {
        std::string desc;
        double price;
        Product() {}
        Product(const std::string& str, double p) : desc(str), price(p) {}
        void display(std::ostream& os) const {
            os << std::setw(FWD) << desc << std::setw(FWP)
                << price << std::endl;
        }

        // cda-conceicao-rodrig - 14/DEC/2017 - begin
        // validate
        // This function throws an exception if the stored price is a negative value
        void validate() {
            if (this->price < 0) throw "*** Negative prices are invalid ***";
        }
        // cda-conceicao-rodrig - 14/DEC/2017 - end
    };
}

#endif // !W9_ELEMENT_H__