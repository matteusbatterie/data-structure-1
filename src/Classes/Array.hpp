#pragma once

namespace Standard
{
    template <class T>
    class Array
    {
    private:
        T* _array;
        unsigned long int _size;

        typedef T* iterator;
        typedef const T* const_iterator;

    public:
        Array() {
            this->_array = (T*)malloc(0);
            this->_size = 0;
        }
        ~Array() {
            free(_array);
        }

        T* rawArray() const { return this->_array; }
        unsigned long int size() const { return this->_size; }

        void insert(T newItem) {
            _array = (T*)realloc(_array, (++_size) * sizeof(T));
            _array[_size - 1] = newItem;
        }

        // Range based for loop functions
        iterator begin() { return &_array[0]; }
        const_iterator begin() const { return &_array[0]; }
        iterator end() { return &_array[_size]; }
        const_iterator end() const { return &_array[_size]; }
    };
}