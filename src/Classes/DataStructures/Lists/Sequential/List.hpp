#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "../../../Entities/Person.hpp"

#include "../../../../Configuration/FeatureFlag.hpp"
#include "../../../Util/Timer.hpp"

using namespace Configuration;
using namespace Util;

namespace DataStructure::Lists::Sequential
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
        List(T* array, long size) {
            _first = array;
            _size = size;
        }
        List() {
            this->_first = new T[0];
            this->_size = 0;
        }
        ~List()
        {
            delete[] this->_first;
        }

        // Returns the size of the list
        unsigned long size() const { return this->_size; }

        void append(T data);
        void insert(T data, long position);

        void pop();
        void remove(int position);

        T& find(const T data) const;
        void findAt(int position) const;
        void findAndPrint(const T data) const;

#pragma region Sorts
        List<T>* selectionSort();
        List<T>* insertionSort();
        List<T>* bubbleSort();
        List<T>* shellSort();
        List<T>* quickSort();
        List<T>* mergeSort();
#pragma endregion

        // Temporary solution to display data in the screen.
        // TO DO: Implement an overload to the << operator.
        void print() const
        {
            for (int index = 0; index < _size; index++)
                std::cout << _first[index] << '\n';
        }

    private:
#pragma region Auxiliary methods
        List<T>* quickSortRecursive(long low, long high);
        long quickSortPartition(long start, long end);

        void mergeSortRecursive(long start, long end);
        void mergeSortMerge(long start, long middle, long end);
#pragma endregion

    public:
#pragma region Operator Overloads
        template <class E>
        friend ostream& operator<<(ostream& os, const List<E>& list);
        List<T>& operator=(const List<T>& source);
#pragma endregion
    };

    /**
     * Appends a new element at the end of the list
     * @param data New element to be added into the list
    */
    template <class T>
    void List<T>::append(T data)
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        T* newList = new T[++_size];
        for (long index = 0; index < _size - 1; index++)
            newList[index] = _first[index];

        newList[_size - 1] = data;

        delete[] _first;
        _first = newList;

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\n\nAPPEND operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;            // created new list
                assignmentCounter += _size;     // copying "_size" positions to new array
                assignmentCounter++;            // assigning new data
                assignmentCounter++;            // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter += _size;      // for loop has "_size" validations

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }

    /**
     * Inserts a new element into a given position of the list
     * @param data New element to be added into the list
     * @param position Desired position where the new element should be added (starting at 0)
    */
    template <class T>
    void List<T>::insert(T data, long position)
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        if (position > _size || position < 0)
        {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        T* newList = new T[++_size];
        for (long index = 0; index < position; index++)
            newList[index] = _first[index];

        newList[position] = data;

        for (long index2 = position + 1; index2 < _size; index2++)
            newList[index2] = _first[index2 - 1];

        delete[] _first;
        _first = newList;

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {

            std::cout << "\nINSERT operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;            // created new list
                assignmentCounter += _size;     // both for loops have "_size" assignments
                assignmentCounter++;            // copying new data
                assignmentCounter++;            // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;             // checking if position is valid
                conditionCounter += _size;      // both for loops have "_size" validations

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }

    /**
     * Removes the last element of the list
    */
    template <class T>
    void List<T>::pop()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        if (_size == 0)
        {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        T* newList = new T[--_size];

        for (long index = 0; index < _size; index++)
            newList[index] = _first[index];

        delete[] _first;
        _first = newList;

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nPOP operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;            // created new list
                assignmentCounter += _size;     // for loop has "_size" assignments
                assignmentCounter++;            // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;             // checks if there is an element to remove
                conditionCounter += _size;      // for loop has "_size" validations

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }

    /**
     * Removes an element of the list at a given position
     * @param position Position of the element to be removed (starting at 0)
    */
    template <class T>
    void List<T>::remove(int position)
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

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

        T* newList = new T[--_size];

        for (long index = 0; index < position; index++)
            newList[index] = _first[index];

        for (long index = position + 1; index < _size + 1; index++)
            newList[index - 1] = _first[index];

        delete[] _first;
        _first = newList;

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nREMOVE operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter++;                        // created new list
                assignmentCounter += _size;                 // for loop has "_size" assignments
                assignmentCounter++;                        // assigning new list

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter++;                         // checks if position is valid
                conditionCounter++;                         // checks if there list is empty
                conditionCounter += _size;                  // for loop has "_size" validations

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }

    /**
     * Looks for a given element if it is present in the list
     * @param data Element to be found
     * @return Found element if present, `nullptr` if not present
    */
    template <class T>
    T& List<T>::find(const T data) const
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion
#pragma region Assignment and Condition Counting logic
        long iterations = 0;
#pragma endregion

        T* result = nullptr;
        for (long index = 0; index < _size; index++)
            if (_first[index] == data) {
                result = _first[iterations = index];
                break;
            }

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nSearch operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter += iterations;    // number of increments until the element was found

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter += iterations;     // number of comparisons in the for loop until the element was found
                conditionCounter += iterations;     // number of comparisons in the if clause until the element was found

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion

        return result;
    }
    /**
     * To be implemented. Searchs for an element at a given position
     * @param position Position of the desired element (starting at 0)
    */
    template <class T>
    void List<T>::findAt(int position) const {
        std::cout << "To be implemented.\n";
    }
    /**
     * Looks for a given element and prints it, if present in the list
     * @param data Element to be found
    */
    template <class T>
    void List<T>::findAndPrint(const T data) const
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion
#pragma region Assignment and Condition Counting logic
        long iterations = 0;
#pragma endregion

        for (long index = 0; index < _size; index++)
            if (_first[index] == data) {
                std::cout << index + 1 << ") " << _first[iterations = index] << '\n';
                break;
            }

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nSearch operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCounter = 0;
                assignmentCounter += iterations;    // number of increments until the element was found

                std::cout << "Count of assignments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCounter = 0;
                conditionCounter += iterations;     // number of comparisons in the for loop until the element was found
                conditionCounter += iterations;     // number of comparisons in the if clause until the element was found

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }

#pragma region Sorts
    /**
     * Uses the Selection Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::selectionSort()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

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

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nSelection Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;
                assignmentCounter += _size;                     // "currentElement" assignments
                assignmentCounter += _size;                     // "smallestElement" assignments
                assignmentCounter += _size;                     // replacing "currentPosition element" with "smallestElement"
                assignmentCounter += _size;                     // replacing "smallestPosition element" with "currentElement";

                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;
                conditionCounter += _size * (_size + 1) / 2;    // numbers of times there happened a comparison

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion

        return this;
    }
    /**
     * Uses the Insertion Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::insertionSort()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        for (long currentPosition = 1; currentPosition < _size; currentPosition++)
        {
            T currentElement = _first[currentPosition];
            long replacePosition = currentPosition - 1;

            for (replacePosition; replacePosition >= 0 && currentElement <= _first[replacePosition]; replacePosition--)
                _first[replacePosition + 1] = _first[replacePosition];

            _first[replacePosition + 1] = currentElement;
        }

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nInsertion Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;
                assignmentCounter += _size - 1;         // "currentElement" assignments within the for loop
                assignmentCounter += _size - 1;         // "replacePosition" assignments within the for loop
                assignmentCounter += _size - 1;         // "replacePosition element" assignments within the for loop

                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;
                conditionCounter += _size - 1;          // number of comparisons throughout the for loop

                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion

        return this;
    }
    /**
     * Uses the Bubble Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::bubbleSort()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        for (long currentLoop = 1; currentLoop < _size - 1; currentLoop++)
            for (long currentIndex = 0; currentIndex < _size - currentLoop; currentIndex++)
                if (_first[currentIndex] > _first[currentIndex + 1])
                {
                    T currentItem = _first[currentIndex];
                    _first[currentIndex] = _first[currentIndex + 1];
                    _first[currentIndex + 1] = currentItem;
                }

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nBubble Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }
    /**
     * Uses the Shell Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::shellSort()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

#pragma region Example
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
#pragma endregion

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

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nShell Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }
    /**
     * Uses the Quick Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::quickSort()
    {
#pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        long low = 0;
        long high = _size - 1;
        quickSortRecursive(low, high);

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nQuick Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion
    }
    /**
     * Uses the Merge Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::mergeSort()
    {
        #pragma region Timer logic
        if (FeatureFlag::TIMER)
            Timer::begin();
#pragma endregion

        if (_size < 1) return nullptr;

        mergeSortRecursive(0, _size - 1);

#pragma region Assignment and Condition Counting logic
        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER) {
            std::cout << "\nMerge Sort operation log:\n";

            if (FeatureFlag::ASSIGNMENT_COUNTER) {
                long assignmentCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of assigments: " << assignmentCounter << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER) {
                long conditionCounter = 0;

                std::cout << "Due to difficulties implementing this logic, the counter was not implemented.\n";
                std::cout << "Count of comparisons: " << conditionCounter << '\n';
            }
        }
#pragma endregion
#pragma region Timer logic
        if (FeatureFlag::TIMER) {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
#pragma endregion

        return this;
    }
#pragma endregion

#pragma region Auxiliary methods
    /**
     * Auxiliary method called by quickSort() that handles the recursive calls
     * @param low Starting index in current iteration
     * @param high Ending index in current iteration
     * @return The list once the recursive calls are over
    */
    template <class T>
    List<T>* List<T>::quickSortRecursive(long low, long high)
    {
        if (low >= high)
            return this;

        long partitionIndex = quickSortPartition(low, high);

        quickSortRecursive(low, partitionIndex - 1);
        quickSortRecursive(partitionIndex + 1, high);
    }
    /**
     * Auxiliary method called by quickSortRecursive() that handles what partition should be picked for the next iterations
     * @param start Starting index in current iteration
     * @param end Ending index in current iteration
     * @return Index of the position to be partitioned
    */
    template <class T>
    long List<T>::quickSortPartition(long start, long end)
    {
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
#pragma endregion

#pragma region Operator Overloads
    template <class T>
    ostream& operator<<(ostream& os, const List<T>& list)
    {
        if (list.size() < 1)
            return os << "Empty list.\n";

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
        if (this == &source)
            return *this;

        delete[] _first;

        this->_size = source.size();
        this->_first = new T[_size];
        std::copy(source._first, source._first + source.size(), _first);

        return *this;
    }
#pragma endregion
}
