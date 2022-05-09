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
        T* _first;

    private:
        unsigned long _size;

    public:
        List(const List<T>& copy)
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

        T& find(const T data) const;
        void findAt(int position) const;
        void findAndPrint(const T data) const;

        List<T>* selectionSort();
        List<T>* insertionSort();
        List<T>* bubbleSort();
        List<T>* shellSort();
        List<T>* quickSort();
        List<T>* mergeSort();


        // temporary solution
        void print()
        {
            for (int index = 0; index < _size; index++)
                std::cout << _first[index] << '\n';
        }

        template <class E>
        friend ostream& operator<<(ostream& os, const List<E>& list);
        List<T>& operator=(const List<T>& source);

    private:
        List<T>* quickSortRecursive(long low, long high);
        long quickSortPartition(long start, long end);

        void mergeSortRecursive(long start, long end);
        void mergeSortMerge(long start, long middle, long end);

    };

    template <class T>
    void List<T>::append(T data)
    {
        // if (FeatureFlag::TIMER)
        //     Timer::begin();

        T *newList = new T[++_size];
        for (long index = 0; index < _size - 1; index++)
            newList[index] = _first[index];

        newList[_size - 1] = data;

        delete[] _first;
        _first = newList;

        // if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        // {
        //     std::cout << "\nAPPEND operation log:\n";

        //     if (FeatureFlag::ASSIGNMENT_COUNTER)
        //     {
        //         long assignmentCounter = 0;
        //         assignmentCounter++;        // created new list
        //         assignmentCounter += _size; // copying "_size" positions to new array
        //         assignmentCounter++;        // assigning new data
        //         assignmentCounter++;        // assigning new list

        //         std::cout << "Count of assignments: " << assignmentCounter << '\n';
        //     }
        //     if (FeatureFlag::CONDITION_COUNTER)
        //     {
        //         long conditionCounter = 0;
        //         conditionCounter += _size; // checking if for loop has reached end
        //         conditionCounter++;        // additional check that breaks out of loop

        //         std::cout << "Count of comparisons: " << conditionCounter << '\n';
        //     }
        // }
        // if (FeatureFlag::TIMER)
        // {
        //     Timer::end();
        //     std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        // }
    }

    template <class T>
    void List<T>::insert(T data, long position)
    {
        // if (FeatureFlag::TIMER)
        //     Timer::begin();

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

        // if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        // {

        //     std::cout << "\nINSERT operation log:\n";

        //     if (FeatureFlag::ASSIGNMENT_COUNTER)
        //     {
        //         long assignmentCounter = 0;
        //         assignmentCounter++;                         // created new list
        //         assignmentCounter += position;               // copying "position" positions to new array
        //         assignmentCounter++;                         // copying new data
        //         assignmentCounter += _size - (position + 1); // copying "size - (position + 1)" positions to new array
        //         assignmentCounter++;                         // assigning new list

        //         std::cout << "Count of assignments: " << assignmentCounter << '\n';
        //     }
        //     if (FeatureFlag::CONDITION_COUNTER)
        //     {
        //         long conditionCounter = 0;
        //         conditionCounter++;                         // checking if position is valid
        //         conditionCounter += position;               // checking if for loop has reached end
        //         conditionCounter++;                         // additional check that breaks out of loop
        //         conditionCounter += _size - (position + 1); // checking if second for loop has reached end
        //         conditionCounter++;                         // additiona check that breaks out fo second loop

        //         std::cout << "Count of comparisons: " << conditionCounter << '\n';
        //     }
        // }
        // if (FeatureFlag::TIMER)
        // {
        //     Timer::end();
        //     std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        // }
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
        for (long index = 0; index < _size; index++)
            if (_first[index] == data)
                return _first[index];
    }
    template <class T>
    void List<T>::findAndPrint(const T data) const
    {
        for (long index = 0; index < _size; index++)
                if (_first[index] == data)
                    std::cout << index + 1 << ") " << _first[index] << '\n';
    }

    template <class T>
    List<T>* List<T>::selectionSort()
    {
        if(FeatureFlag::TIMER)
            Timer::begin();

        for (long currentPosition = 0; currentPosition < _size; currentPosition++)
        {
            T currentElement = _first[currentPosition];

            long smallestPosition = currentPosition;
            T smallestElement = _first[smallestPosition];
            for (long j = currentPosition + 1; j < _size; j++)
                if (_first[j] < smallestElement)
                    smallestElement = _first[smallestPosition = j];

            _first[currentPosition] = smallestElement;
            _first[smallestPosition] = currentElement;
        }

        if(FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;
                for (long currentPosition = 0; currentPosition < _size; currentPosition++)
                {
                    assignmentCounter += 3;
                    long smallestPosition = currentPosition;
                    T smallestElement = _first[smallestPosition];
                    for (long j = currentPosition + 1; j < _size; j++)
                        if (_first[j] < smallestElement)
                            assignmentCounter += 2;

                    assignmentCounter += 2;
                }
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;
                for (long currentPosition = 0; currentPosition < _size; currentPosition++)
                {
                    for (long j = currentPosition + 1; j < _size; j++)
                        conditionCounter += 2;

                    conditionCounter++;
                }

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if(FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }

        return this;
    }
    template <class T>
    List<T>* List<T>::insertionSort()
    {
        if(FeatureFlag::TIMER)
            Timer::begin();

        for (long currentPosition = 1; currentPosition < _size; currentPosition++)
        {
            T currentElement = _first[currentPosition];
            long replacePosition = currentPosition - 1;

            for (replacePosition; replacePosition >= 0 && currentElement <= _first[replacePosition]; replacePosition--)
                _first[replacePosition + 1] = _first[replacePosition];

            _first[replacePosition + 1] = currentElement;
        }

        if(FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                for (long currentPosition = 1; currentPosition < _size; currentPosition++)
                {
                    assignmentCounter += 2; 
                    T currentElement = _first[currentPosition];
                    long replacePosition = currentPosition - 1;
                    for (replacePosition; replacePosition >= 0 && currentElement <= _first[replacePosition]; replacePosition--)
                        assignmentCounter++;

                    assignmentCounter++;
                }

                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                for (long currentPosition = 1; currentPosition < _size; currentPosition++)
                {
                    T currentElement = _first[currentPosition];
                    long replacePosition = currentPosition - 1;
                    for (replacePosition; replacePosition >= 0 && currentElement <= _first[replacePosition]; replacePosition--)
                        conditionCounter++;

                    conditionCounter++;
                }

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if(FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }

        return this;
    }
    template <class T>
    List<T>* List<T>::bubbleSort()
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        for (long currentLoop = 1; currentLoop < _size - 1; currentLoop++)
            for (long currentIndex = 0; currentIndex < _size - currentLoop; currentIndex++)
                if (_first[currentIndex] > _first[currentIndex + 1])
                {
                    T currentItem = _first[currentIndex];
                    _first[currentIndex] = _first[currentIndex + 1];
                    _first[currentIndex + 1] = currentItem;
                }

        // if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
        //     if (FeatureFlag::ASSIGNMENT_COUNTER) {
        //         long assignmentCounter = 0;

        //         for (long currentLoop = 0; currentLoop < _size; currentLoop++)
        //             for (long currentIndex = 0; currentIndex < _size - currentLoop; currentIndex++)
        //                 if (_first[currentIndex] > _first[currentIndex + 1])
        //                     assignmentCounter += 3;

        //         std::cout << "Count of assigments: " << assignmentCounter << '\n';
        //     }
        //     if (FeatureFlag::CONDITION_COUNTER) {
        //         long conditionCounter = 0;

        //         for (long currentLoop = 0; currentLoop < _size; currentLoop++) {
        //             for (long currentIndex = 0; currentIndex < _size - currentLoop; currentIndex++)
        //                 conditionCounter += 2;
        //             conditionCounter++;
        //         }

        //         std::cout << "Count of comparisons: " << conditionCounter << '\n';
        //     }
        // }

        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }
    template <class T>
    List<T>* List<T>::shellSort()
    {
        if (FeatureFlag::TIMER)
            Timer::begin();
             
        // example
        //  0  1  2  3  4  5  6  7  8  9
        // 45 23 53 43 18 24 08 95 10 15
        // gap == 5
        // 45             24                // sublist 1
        //    23             08             // sublist 2
        //       53             95          // sublist 3
        //          43             10       // sublist 4
        //             18             15    // sublist 5

        // 24 08 53 10 15 45 23 95 43 18
        //                                  gap == 2
        // 24	 53    15    23    43       // sublist 1
        //    08    10    45    95    18    // sublist 2

        // 15 08 23 10 24 18 53 45 43 95
        //                                  gap == 1
        // 08 15 23 10 24 18 53 45 43 95
        // 08 10 15 23 24 18 53 45 43 95
        // 08 10 15 18 23 24 53 45 43 95
        // 08 10 15 18 23 24 45 53 43 95
        // 08 10 15 18 23 24 43 45 53 95

        long initialGap = _size / 2;
        for (long gap = initialGap; gap > 0; gap /= 2)
        {
            for (long subListFirst = gap; subListFirst < _size; subListFirst++)
            {
                T currentItem = _first[subListFirst];

                long replacePosition;
                for (replacePosition = subListFirst; replacePosition >= gap && _first[replacePosition - gap] > currentItem; replacePosition -= gap)
                    _first[replacePosition] = _first[replacePosition - gap];

                _first[replacePosition] = currentItem;
            }
        }

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                long initialGap = _size / 2;
                for (long gap = initialGap; gap > 0; gap /= 2)
                    for (long subListFirst = gap; subListFirst < _size; subListFirst++)
                    {
                        assignmentCounter++;
                        T currentItem = _first[subListFirst];
                        long replacePosition;
                        for (replacePosition = subListFirst; replacePosition >= gap && _first[replacePosition - gap] > currentItem; replacePosition -= gap)
                            assignmentCounter++;

                        assignmentCounter++;
                    }
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                for (long gap = initialGap; gap > 0; gap /= 2)
                {
                    for (long subListFirst = gap; subListFirst < _size; subListFirst++)
                    {
                        T currentItem = _first[subListFirst];
                        long replacePosition;
                        for (replacePosition = subListFirst; replacePosition >= gap && _first[replacePosition - gap] > currentItem; replacePosition -= gap)
                            conditionCounter++;

                        conditionCounter++;
                    }
                    conditionCounter++;
                }

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }
    template <class T>
    List<T>* List<T>::quickSort()
    {
        long low = 0;
        long high = _size - 1;
        quickSortRecursive(low, high);
    }
    template <class T>
    List<T>* List<T>::mergeSort()
    {
        if (_size < 1) return nullptr;

        mergeSortRecursive(0, _size - 1);

        return this;
    }

    template <class T>
    List<T>* List<T>::quickSortRecursive(long low, long high)
    {
        if (low >= high)
            return this;

        long partitionIndex = quickSortPartition(low, high);

        quickSortRecursive(low, partitionIndex - 1);
        quickSortRecursive(partitionIndex + 1, high);
    }
    template <class T>
    long List<T>::quickSortPartition(long start, long end)
    {
        if(FeatureFlag::TIMER)
            Timer::begin();

        T pivot = _first[start];

        long count = 0;
        for (int i = start + 1; i <= end; i++)
            if (_first[i] <= pivot)
                count++;

        long pivotIndex = start + count;
        T currentItem = _first[pivotIndex];
        _first[pivotIndex] = _first[start];
        _first[start] = currentItem;

        long incrementor = start;
        long decrementor = end;
        while (incrementor < pivotIndex && decrementor > pivotIndex)
        {
            while (_first[incrementor] <= pivot)
                incrementor++;
            while (_first[decrementor] > pivot)
                decrementor--;

            if (incrementor < pivotIndex && decrementor > pivotIndex)
            {
                currentItem = _first[incrementor];
                _first[incrementor] = _first[decrementor];
                _first[decrementor] = currentItem;
                incrementor++;
                decrementor--;
            }
        }

        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }

        return pivotIndex;
    }

    template <class T>
    void List<T>::mergeSortRecursive(long start, long end)
    {
        if (start >= end) return;

        long middle = start + (end - start) / 2;
        mergeSortRecursive(start, middle);
        mergeSortRecursive(middle + 1, end);
        mergeSortMerge(start, middle, end);
    }
    template <class T>
    void List<T>::mergeSortMerge(long start, long middle, long end)
    {
        long leftArraySize = middle - start + 1;
        long rightArraySize = end - middle;
        T* leftArray = new T[leftArraySize];
        T* rightArray = new T[rightArraySize];

        // Copying left data to left array (begin : middle)
        for (long index = 0; index < leftArraySize; index++)
            leftArray[index] = _first[start + index];
        // Copying right data to right array (middle + 1 : end)
        for (long index = 0; index < rightArraySize; index++)
            rightArray[index] = _first[middle + 1 + index];

        long indexLeftArray = 0;
        long indexRightArray = 0;
        long indexMergedArray = start;
        // Merging left and right arrays into original array
        while (indexLeftArray < leftArraySize && indexRightArray < rightArraySize)
        {
            if (rightArray[indexRightArray] > leftArray[indexLeftArray])
                _first[indexMergedArray] = leftArray[indexLeftArray++];
            else
                _first[indexMergedArray] = rightArray[indexRightArray++];

            indexMergedArray++;
        }

        // Copying remaining elements, if any, from left array
        while (indexLeftArray < leftArraySize) {
            _first[indexMergedArray] = leftArray[indexLeftArray++];
            indexMergedArray++;
        }
        // Copying remaining elements, if any, from right array
        while (indexRightArray < rightArraySize) {
            _first[indexMergedArray] = rightArray[indexRightArray++];
            indexMergedArray++;
        }

        delete[] leftArray;
        delete[] rightArray;
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
