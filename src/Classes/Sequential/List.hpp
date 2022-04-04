#pragma once
#include <string>
#include <iostream>
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
        unsigned long _size;

    public:
        List(const List<T>& copy) {
            _first = new T[copy.size()];
            std::copy(copy._first, copy._first + copy.size(), _first);
            _size = copy.size();
        }
        List() {
            this->_first = new T[0];
            this->_size = 0;
        }
        ~List() {
            delete[] this->_first;
        }

        unsigned long size() const { return this->_size; }


        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        T& find(const T data) const;
        void findAt(int position) const;


        template <class E>
        friend ostream& operator<<(ostream& os, const List<E>& list);
        List<T>& operator=(const List<T>& source);
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

    template <class T>
    void List<T>::insert(T data, int position)
    {
        if (position > _size || position < 0) {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        T* newList = new T[++_size];

        for (int index = 0;
            index < position;
            index++)
        {
            newList[index] = _first[index];
        }
        newList[position] = data;

        for (int index = position + 1;
            index < _size - 1;
            index++)
        {
            newList[index] = _first[index];
        }

        delete[] _first;
        _first = newList;
    }

    template <class T>
    void List<T>::pop()
    {
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        T* newList = new T[--_size];
        for (int index = 0;
            index < _size;
            index++)
        {
            newList[index] = _first[index];
        }

        delete[] _first;
        _first = newList;
    }

    template <class T>
    void List<T>::remove(int position)
    {
        if (position > _size || position < 0) {
            std::cout << "Invalid range for remotion.\n";
            return;
        }

        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        T* newList = new T[--_size];
        for (int index = 0; index < position;index++)
            newList[index] = _first[index];

        for (int index = position + 1; index < _size; index++)
            newList[index] = _first[index];

        delete[] _first;
        _first = newList;
    }

    template <class T>
    T& List<T>::find(const T) const
    {
        
    }

    template <class T>
    ostream& operator<<(ostream& os, const List<T>& list)
    {
        if (list.size() < 1) return os << "Empty list.\n";

        os << "[" << list._first[0] << "]";

        T* iterator = list._first;
        for (unsigned int counter = 1;
            counter < list.size();
            counter++)
            os << "\n[" << iterator[counter] << "]";

        return os;
    }

    template <class T>
    List<T>& List<T>::operator=(const List<T>& source)
    {
        if (this == &source) return *this;

        delete[] _first;

        this->_size = source.size();
        this->_first = new T[_size];
        std::copy(source._first, source._first + source.size(), _first);

        return *this;
    }
}
