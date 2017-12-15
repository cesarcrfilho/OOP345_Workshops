/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Dec 14 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 09 - List.h
---------------------------------------------------------------*/

// Workshop 9 - Smart Pointers
// List.h

// cda-conceicao-rodrig - 14/DEC/2017 - begin
#ifndef W9_LIST_H__
#define W9_LIST_H__
// cda-conceicao-rodrig - 14/DEC/2017 - end
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
// cda-conceicao-rodrig - 14/DEC/2017 - begin
#include <memory> // smart pointers
// cda-conceicao-rodrig - 14/DEC/2017 - end

namespace w9 {
    template <typename T>
    class List {
        std::vector<T> list;
    public:
        List() { }
        List(const char* fn) {
            std::ifstream file(fn);
            if (!file)
                throw std::string("*** Failed to open file ") +
                std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
        }
        size_t size() const { return list.size(); }
        const T& operator[](size_t i) const { return list[i]; }
        // cda-conceicao-rodrig - 14/DEC/2017
        // changed the raw pointer parameter to a smart pointer one
        void operator+=(std::shared_ptr<T> p) {
            list.push_back(*p);
        }
        void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
        l.display(os);
        return os;
    }
}

#endif //!W9_LIST_H__
