/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : Oct 06 2017
Class       : OOP345 - Object Oriented Software Development Using C++
Description : Workshop 04 - KVList.h
---------------------------------------------------------------*/

#ifndef SICT_KVLIST_H__
#define SICT_KVLIST_H__

/////////////////////////////////////////////////////////////////
//                   Class KVList Declaration                  //
/////////////////////////////////////////////////////////////////
template <typename K, typename V, int N>
class KVList {
private:
    K m_keys[N];
    V m_values[N];
    size_t m_size;

    // isWithinBoundaries
    // checks if an integer i is within the array boundaries
    bool isWithinBoundaries(int i) const {
        return (i >= 0 && i < m_size);
    }

public:
    // default constructor
    KVList() : m_size(0) { }

    // size
    // returns the number of entries in the key-value list
    size_t size() const { return m_size; }

    // key
    // returns an unmodifiable reference to the key of element i in the list
    const K& key(int i) const {
        // check parameter
        if (isWithinBoundaries(i))
            return m_keys[i];
    }

    // value
    // returns an unmodifiable reference to the value of element i in the list
    const V& value(int i) const {
        // check parameter
        if (isWithinBoundaries(i))
            return m_values[i];
    }

    // add
    // adds a new element to the list if room exists and returns a reference
    // to the current object, does nothing if no room exists
    KVList& add(const K& key, const V& value) {
        // check if there's room
        if (m_size < N) {
            m_keys[m_size] = key;
            m_values[m_size] = value;
            m_size++;
        }
        return *this;
    }

    // find
    // returns the index of the first element in the list with a key equal
    // to k - defaults to 0
    int find(const K& k) const {
        int result = 0;

        // loop through the array and check the keys
        for (unsigned i = 0; i < m_size; i++) {
            if (m_keys[i] == k) {
                result = i;
                break; // *since the specification asks for the FIRST element
            }
        }
        return result;
    }

    // replace
    // replaces element i in the list with the key and value received
    // and returns a reference to the current object
    KVList& replace(int i, const K& k, const V& v) {
        if (isWithinBoundaries(i)) {
            m_keys[i] = k;
            m_values[i] = v;
        }
        return *this;
    }
};

#endif // !SICT_KVLIST_H__

