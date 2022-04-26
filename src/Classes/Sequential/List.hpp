#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "../Entities/Person.hpp"

#include "../../Configuration/FeatureFlag.hpp"
#include "../Util/Timer.hpp"

using namespace Configuration;
using namespace Util;

namespace DataStructure::Query::Sequential
{
    template <class T>
    class List
    {
    public:
        T *_first;

    private:
        unsigned long _size;

    public:
        List(const List<T> &copy)
        {
            _first = new T[copy.size()];
            std::copy(copy._first, copy._first + copy.size(), _first);
            _size = copy.size();
        }
        List()
        {
            this->_first = new T[0];
            this->_size = 0;
        }
        ~List()
        {
            delete[] this->_first;
        }

        unsigned long size() const { return this->_size; }

        void append(T data);
        void insert(T data, long position);

        void pop();
        void remove(int position);

        T &find(const T data) const;
        void findAt(long position) const;

        // temporary solution
        void print()
        {
            for (int index = 0; index < _size; index++)
                std::cout << _first[index] << '\n';
        }

        template <class E>
        friend ostream &operator<<(ostream &os, const List<E> &list);
        List<T> &operator=(const List<T> &source);
    };

    template <class T>
    void List<T>::append(T data)
    {
        std::chrono::steady_clock::time_point begin;
        if (FeatureFlag::TIMER)
            Timer::begin();

        T *newList = new T[++_size];
        for (long index = 0; index < _size - 1; index++)
            newList[index] = _first[index];

        newList[_size - 1] = data;

        delete[] _first;
        _first = newList;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nAPPEND operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;        // created new list
                assignmentCounter += _size; // copying "_size" positions to new array
                assignmentCounter++;        // assigning new data
                assignmentCounter++;        // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter += _size; // checking if for loop has reached end
                conditionCounter++;        // additional check that breaks out of loop

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    template <class T>
    void List<T>::insert(T data, long position)
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        if (position > _size || position < 0)
        {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        T *newList = new T[++_size];
        for (long index = 0; index < position; index++)
            newList[index] = _first[index];

        newList[position] = data;

        for (long index2 = position + 1; index2 < _size; index2++)
            newList[index2] = _first[index2 - 1];

        delete[] _first;
        _first = newList;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {

            std::cout << "\nINSERT operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;                         // created new list
                assignmentCounter += position;               // copying "position" positions to new array
                assignmentCounter++;                         // copying new data
                assignmentCounter += _size - (position + 1); // copying "size - (position + 1)" positions to new array
                assignmentCounter++;                         // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;                         // checking if position is valid
                conditionCounter += position;               // checking if for loop has reached end
                conditionCounter++;                         // additional check that breaks out of loop
                conditionCounter += _size - (position + 1); // checking if second for loop has reached end
                conditionCounter++;                         // additiona check that breaks out fo second loop

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    template <class T>
    void List<T>::pop()
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        if (_size == 0)
        {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        T *newList = new T[--_size];

        for (long index = 0; index < _size; index++)
            newList[index] = _first[index];

        delete[] _first;
        _first = newList;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nPOP operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;        // created new list
                assignmentCounter += _size; // copying "_size" positions to new list
                assignmentCounter++;        // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;        // checks if there is an element to remove
                conditionCounter += _size; // checking if for loop has reached end
                conditionCounter++;        // additional check that breaks out of loop

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    template <class T>
    void List<T>::remove(int position)
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        if (position > _size || position < 0)
        {
            std::cout << "Invalid range for remotion.\n";
            return;
        }

        if (_size == 0)
        {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        T *newList = new T[--_size];

        for (long index = 0; index < position; index++)
            newList[index] = _first[index];

        for (long index = position + 1; index < _size + 1; index++)
            newList[index - 1] = _first[index];

        delete[] _first;
        _first = newList;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nREMOVE operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;                         // created new list
                assignmentCounter += position;               // copying "position" positions to new list
                assignmentCounter += _size - (position + 1); // copying "_size - (position + 1)" positions to new list]
                assignmentCounter++;                         // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;                         // checks if position is valid
                conditionCounter++;                         // checks if there list is empty
                conditionCounter += position;               // checking if for loop has reached end
                conditionCounter++;                         // additional check that breaks out of loop
                conditionCounter += _size - (position + 1); // checking if second for loop has reached end
                conditionCounter++;                         // additional check that breaks out of second loop

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    template <class T>
    T &List<T>::find(const T data) const
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        for (long index = 0; index < _size; index++)
        {
            if (_first[index] == data)
            {
                if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
                {
                    std::cout << "\nFIND operation log:\n";

                    if (FeatureFlag::ASSIGNMENT_COUNTER)
                    {
                        long assignmentCounter = 0;

                        std::cout << "Count of assignments: " << assignmentCounter << '\n';
                    }
                    if (FeatureFlag::CONDITION_COUNTER)
                    {
                        long conditionCounter = 0;
                        conditionCounter += index * 2; // current quantity of loops made and at least two comparisons

                        std::cout << "Count of comparisons: " << conditionCounter << '\n';
                    }
                }
                if (FeatureFlag::TIMER)
                {
                    Timer::end();
                    std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
                }
                return _first[index];
            }
        }

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nFIND operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter += _size * 2; // current quantity of loops made and at least two comparisons

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    template <class T>
    ostream &operator<<(ostream &os, const List<T> &list)
    {
        if (list.size() < 1)
            return os << "Empty list.\n";

        os << "[" << list._first[0] << "]";

        T *iterator = list._first;
        for (unsigned int counter = 1;
             counter < list.size();
             counter++)
            os << "\n[" << iterator[counter] << "]";

        return os;
    }

    template <class T>
    List<T> &List<T>::operator=(const List<T> &source)
    {
        if (this == &source)
            return *this;

        delete[] _first;

        this->_size = source.size();
        this->_first = new T[_size];
        std::copy(source._first, source._first + source.size(), _first);

        return *this;
    }
}
