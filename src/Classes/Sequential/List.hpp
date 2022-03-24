#pragma once
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>
#include "../Entities/Person.hpp"

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
        List(const List<T>& copy) {
            _first = new T[copy.size()];
            std::copy(copy._first, copy._first + copy.size(), _first);
            _size = copy._size;
        }
        List() {
            this->_first = new T[0];
            this->_size = 0;
        }
        ~List() {
            delete[] this->_first;
        }


        unsigned int size() const { return this->_size; }

        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        void find(T data);
        void findAt(int position);

        friend ostream& operator<<(ostream& os, const List<T>& list)
        {
            if (list._size < 1) {
                return os << "Empty list.";
            }

            Entities::Person person = list._first[0];
            const string test = person.name();
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

        List<T>& operator=(const List<T>& copy)
        {
            if (this == &copy)
                return *this;

            delete[] _first;

            this->_size = copy.size();
            this->_first = new T[_size];
            std::copy(copy._first, copy._first + copy.size(), _first);

            return *this;
        }
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
