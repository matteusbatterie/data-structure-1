#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "../Entities/Person.hpp"

#include <chrono>

using namespace std;

namespace DataStructure::Query::Sequential
{
    template <class T>
    class List
    {
    public:
        T* _first;
    private:
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

        // temporary solution
        void print() {
            for (int index = 0; index < _size; index++)
                std::cout << _first[index] << '\n';
        }

        template <class E>
        friend ostream& operator<<(ostream& os, const List<E>& list);
        List<T>& operator=(const List<T>& source);
    };

    template <class T>
    void List<T>::append(T data)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        a++;
        T* newList = new T[++_size];

        for (unsigned int index = 0; index < _size - 1; index++)
        {
            c++;
            a++;
            newList[index] = _first[index];
        }
        c++;
        newList[_size - 1] = data;
        a++;

        delete[] _first;
        _first = newList;
        a++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\nAPPEND operation log:\n";
        // std::cout << "Count of assignments: " << a << '\n';
        // std::cout << "Count of comparisons: " << c << '\n';
        // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;

    }

    template <class T>
    void List<T>::insert(T data, int position)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        if (position > _size || position < 0) {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        T* newList = new T[++_size];
        c++;
        a++;

        for (int index = 0; index < position; index++)
        {
            c++;
            a++;
            newList[index] = _first[index];
        }
        c++;

        newList[position] = data;
        a++;

        for (int index2 = position + 1; index2 < _size; index2++)
        {
            c++;
            a++;
            newList[index2] = _first[index2 - 1];
        }
        c++;

        delete[] _first;
        _first = newList;
        a++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\nINSERT operation log:\n";
        // std::cout << "Count of assignments: " << a << '\n';
        // std::cout << "Count of comparisons: " << c << '\n';
        // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    void List<T>::pop()
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        c++;
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        a++;
        T* newList = new T[--_size];
        for (int index = 0; index < _size; index++)
        {
            c++;
            newList[index] = _first[index];
            a++;
        }
        c++;

        delete[] _first;
        _first = newList;
        a++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\nPOP operation log:\n";
        // std::cout << "Count of assignments: " << a << '\n';
        // std::cout << "Count of comparisons: " << c << '\n';
        // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    void List<T>::remove(int position)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        c++;
        if (position > _size || position < 0) {
            std::cout << "Invalid range for remotion.\n";
            return;
        }

        c++;
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        a++;
        T* newList = new T[--_size];
        for (int index = 0; index < position; index++)
        {
            c++;
            a++;
            newList[index] = _first[index];
        }
        c++;

        for (int index = position + 1; index < _size + 1; index++)
        {
            c++;
            a++;
            newList[index - 1] = _first[index];
        }
        c++;

        delete[] _first;
        _first = newList;
        a++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\nREMOVE operation log:\n";
        // std::cout << "Count of assignments: " << a << '\n';
        // std::cout << "Count of comparisons: " << c << '\n';
        // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;

    }

    template <class T>
    T& List<T>::find(const T data) const
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        for (int index = 0; index < _size; index++)
        {
            c++;
            if (_first[index] == data) {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                // std::cout << "\nFIND operation log:\n";
                // std::cout << "Count of assignments: " << a << '\n';
                // std::cout << "Count of comparisons: " << c << '\n';
                // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
                return _first[index];
            }
            c++;
        }
        c++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\nFIND operation log:\n";
        // std::cout << "Count of assignments: " << a << '\n';
        // std::cout << "Count of comparisons: " << c << '\n';
        // std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
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
