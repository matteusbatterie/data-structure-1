#pragma once
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

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
            this->_first = (T*)malloc(0);
            this->_size = 0;
        }
        ~List() {
            free (this->_first);
        }

        unsigned int size() const { return this->_size; }
        void size(const int newSize) { this->_size = newSize; }

        friend ostream& operator<<(ostream &os, const List<T>& list) {
            if(list._size < 1) {
                return os << "Empty list.";
            }

            std::string output = "[" + std::to_string(list._first[0]) + "]";

            unsigned int counter = 1;
            for (T* iterator = list._first;
                counter < list._size;
                iterator++, counter++)
            {
                output = output + ", [" + std::to_string(iterator[counter]) + "]";
            }

            return os << output;
        }

        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        void find(T data);
        void findAt(int position);
    };

    template <class T>
    void List<T>::append(T data)
    {
        _first = (T*)realloc(_first, ++_size * sizeof(T));
        _first[_size - 1] = data;
    }
}

