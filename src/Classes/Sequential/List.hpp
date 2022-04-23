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

        List<T>* selectionSort();
        List<T>* insertionSort();
        List<T>* shellSort();
        List<T>* quickSort();

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

        for (int index = 0; index < position; index++)
            newList[index] = _first[index];

        newList[position] = data;

        for (int index2 = position + 1; index2 < _size; index2++)
            newList[index2] = _first[index2 - 1];

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
        for (int index = 0; index < position; index++)
            newList[index] = _first[index];

        for (int index = position + 1; index < _size + 1; index++)
            newList[index - 1] = _first[index];

        delete[] _first;
        _first = newList;
    }

    template <class T>
    T& List<T>::find(const T data) const
    {
        for (int index = 0; index < _size; index++)
            if (_first[index] == data) return _first[index];
    }

    template <class T>
    List<T>* List<T>::selectionSort()
    {
        for (int currentPosition = 0; currentPosition < _size; currentPosition++)
        {
            T currentElement = _first[currentPosition];

            int smallestPosition = currentPosition;
            T smallestElement = _first[smallestPosition];
            for (int j = currentPosition + 1; j < _size; j++)
                if (_first[j] < smallestElement)
                    smallestElement = _first[smallestPosition = j];

            _first[currentPosition] = smallestElement;
            _first[smallestPosition] = currentElement;
        }

        return this;
    }
    template <class T>
    List<T>* List<T>::insertionSort()
    {
        for (int currentPosition = 1; currentPosition < _size; currentPosition++)
        {
            T currentElement = _first[currentPosition];
            int replacePosition;

            for (int j = currentPosition - 1; j >= 0 && currentElement <= _first[j]; j--)
                _first[replacePosition = j + 1] = _first[j];

            _first[replacePosition] = currentElement;
        }

        return this;
    }
    template <class T>
    List<T>* List<T>::shellSort()
    {
        // example
        //  0  1  2  3  4  5  6  7  8  9
        // 45 23 53 43 18 24 08 95 10 15

        // 45             24
        //    23             08
        //       53             95
        //          43             10
        //             18             15
                    
        // 24 08 53 10 15 45 23 95 43 18
            
        // 24	 53    15    23    43 
        //    08    10    45    95    18
        
        // 15 08 23 10 24 18 53 45 43 95
        // 08 15 23 10 24 18 53 45 43 95
        // 08 10 15 23 24 18 53 45 43 95
        // 08 10 15 18 23 24 53 45 43 95
        // 08 10 15 18 23 24 45 53 43 95
        // 08 10 15 18 23 24 43 45 53 95  

        int initialGap = _size/2;
        for (int gap = initialGap; gap > 0; gap /= 2)
        {
            for (int subListFirst = gap; subListFirst < _size; subListFirst++)
            {

            }
        }



        for(int gap = _size/2; gap > 0; gap /= 2)
            for(int i = gap; i < _size. i++)
            {
                T temp = _first[i];

                int j;
                for(j = i; j >= gap && _first[j - gap] > temp; j -= gap)
                    _first[j] = _first[j - gap];
                
                _first[j] = temp;
            }
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
