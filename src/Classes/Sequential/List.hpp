#pragma once
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

namespace DataStructure::Query::Sequential
{
    template <class T>
    class List
    {
    private:
        T* _first;
        unsigned int _size;

    public:
        List() {
            this->_first = new T[0];
            this->_size = 0;
        }
        ~List() {
            delete[] this->_first;
        }

        unsigned int size() const { return this->_size; }
        void size(const int newSize) { this->_size = newSize; }

        friend ostream& operator<<(ostream& os, const List<T>& list) {
            if (list._size < 1) {
                return os << "Empty list.";
            }

            os << "[" << list._first[0] << "]";

            unsigned int counter = 1;
            for (T* iterator = list._first;
                counter < list._size;
                counter++)
            {
                os << endl << "[" << iterator[counter] << "]";
            }

            return os;
        }

        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        void find(T data);
        void findAt(int postheition);
    };

    template <class T>
    void List<T>::append(T data)
    {
        T* newList = new T[++_size];

        for (unsigned int index = 0;
            index < _size - 1;
            index++)
        {
            newList[index] = _first[index]; 
        }
        newList[_size - 1] = data;

        delete[] _first;
        _first = newList;
    }
}

