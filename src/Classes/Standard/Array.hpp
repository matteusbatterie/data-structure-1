#pragma once
#include <iostream>
#include <algorithm>

using std::ostream;

namespace Standard::Query
{
    template <class T>
    class Array
    {
    private:
        T* _array;
        unsigned long _size;

        typedef T* iterator;
        typedef const T* const_iterator;

    public:
        Array(const Array<T>& copy) {
            // to be implemented
        }
        Array(T* array, unsigned long size) {
            _array = new T[size];
            for (unsigned long index = 0;
                index < size;
                index++)
            {
                _array[index] = array[index];
            }
        }
        Array() {
            this->_array = new T[0];
            this->_size = 0;
        }
        ~Array() {
            delete[] _array;
        }

        unsigned long size() const { return this->_size; }

        void insert(T newItem);

        T& begin() { return _array; }
        T& begin() const { return _array; }
        T& end() { return _array + _size; }
        T& end() const { return _array + _size; }

        template <class E>
        friend ostream& operator<<(ostream& os, const Array<T>& array);
        Array<T>& operator=(const Array<T>& copy);
    };

    template <class T>
    void Array<T>::insert(T newItem)
    {
        T* newArray = new T[++_size];
        for (unsigned int index = 0;
            index < _size - 1;
            index++)
        {
            _array[index] = newArray[index];
        }
        newArray[_size - 1] = newItem;

        delete[] _array;
        _array = newArray;
    }

    template <class T>
    ostream& operator<<(ostream& os, const Array<T>& array)
    {
        if (array.size() < 1)
            return os << "Empty list.";

        os << "[" << array._array[0] << "]";
        T* iterator = array._array;
        for (unsigned int counter = 1;
            counter < array.size();
            counter++)
        {
            os << ", [" << iterator[counter] << "]";
        }

        return os;
    }

    template <class T>
    Array<T>& Array<T>::operator=(const Array<T>& copy)
    {
        if (this == &copy) return *this;

        delete[] _array;

        this->_size = copy.size();
        this->_array = new T[_size];
        std::copy(copy._array, copy._array + copy.size(), _array);

        return *this;
    }
}
