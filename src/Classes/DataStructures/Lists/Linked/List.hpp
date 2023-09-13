#pragma once
#include "./Node.hpp"
#include <iostream>

using std::ostream;

namespace DataStructure::Lists::Linked
{
    template <class T>
    class List
    {
    private:
        Node<T>* _first;
        Node<T>* _last;
        unsigned long _size;

    public:
        List(const List<T>& copy)
        {
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
            for (T item : copy)
                this->append(item);
        }
        List()
        {
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
        }
        ~List()
        {
            for (Node<T>* iterator = _first; iterator != _last; iterator = &(iterator->next()))
                delete iterator;
        }

        // Returns the size of the list
        unsigned long size() const { return this->_size; }
        // Returns the first element of the list
        T& first() const { return _first->data(); }
        // Returns the last element of the list
        T& last() const { return _last->data(); }

        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        T& find(const T data);
        T& findAt(int position);

        List<T>* selectionSort();
        List<T>* insertionSort();
        List<T>* bubbleSort();
        List<T>* shellSort();
        List<T>* quickSort();
        List<T>* mergeSort();

        // Temporary solution to display data in the screen.
        // TO DO: Implement an overload to the << operator.
        void print()
        {
            for (Node<T>* iterator = _first;
                iterator != &_last->next();
                iterator = &(iterator->next()))
                std::cout << iterator->data() << '\n';
        }

        // Returns a pointer to the beginning of the list
        Node<T>& begin() const { return *_first; }
        // Returns a pointer to the end of the list
        Node<T>& end() const { return _last->next(); }

#pragma region Operator Overloads
        template <class E>
        friend std::ostream& operator<<(ostream& os, const List<E>& list);
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
        if (FeatureFlag::TIMER)
            Timer::begin();

        _size++;

        if (!_first)
        {
            _first = _last = new Node<T>(data);

            if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
            {
                std::cout << "\nAPPEND operation log:\n";
                if (FeatureFlag::ASSIGNMENT_COUNTER)
                {
                    long assingmentCount = 0;
                    assingmentCount++;
                    assingmentCount++;
                    std::cout << "Count of assignments: " << assingmentCount << '\n';
                }
                if (FeatureFlag::CONDITION_COUNTER)
                {
                    long conditionCount = 0;
                    conditionCount++;
                    std::cout << "Count of comparisons: " << conditionCount << '\n';
                }
            }
            if (FeatureFlag::TIMER)
            {
                Timer::end();
                std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
            }
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->previous(*_last);
        _last->next(*newNode);
        _last = newNode;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nAPPEND operation log:\n";
            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCount = 0;
                assignmentCount++;
                assignmentCount += 4;
                std::cout << "Count of assignments: " << assignmentCount << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCount = 0;
                conditionCount++;
                std::cout << "Count of comparisons: " << conditionCount << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms" << std::endl;
        }
    }

    /**
     * Inserts a new element into a given position of the list
     * @param data New element to be added into the list
     * @param position Desired position where the new element should be added (starting at 0)
    */
    template <class T>
    void List<T>::insert(T data, int position)
    {
        if (FeatureFlag::TIMER)
            Timer::begin();

        if (position > _size || position < 0)
        {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        if (position == _size)
        {
            append(data);
            return;
        }

        _size++;

        if (!_first)
        {
            _first = _last = new Node<T>(data);

            if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
            {
                std::cout << "\nINSERT operation log:\n";
                if (FeatureFlag::ASSIGNMENT_COUNTER)
                {
                    long assignmentCount = 0;
                    assignmentCount++;
                    assignmentCount++;
                    std::cout << "Count of assignments: " << assignmentCount << '\n';
                }
                if (FeatureFlag::CONDITION_COUNTER)
                {
                    long conditionCount = 0;
                    conditionCount++;
                    conditionCount++;
                    conditionCount++;
                    std::cout << "Count of comparisons: " << conditionCount << '\n';
                }
            }
            if (FeatureFlag::TIMER)
            {
                Timer::end();
                std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
            }

            return;
        }

        if (position == 0)
        {
            Node<T>* newNode = new Node<T>(data);
            newNode->next(*_first);
            _first->previous(*newNode);
            _first = newNode;
            if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
            {
                std::cout << "\nINSERT operation log:\n";

                if (FeatureFlag::ASSIGNMENT_COUNTER)
                {
                    long assignmentCount = 0;
                    assignmentCount++;
                    assignmentCount += 4;
                    std::cout << "Count of assignments: " << assignmentCount << '\n';
                }
                if (FeatureFlag::CONDITION_COUNTER)
                {
                    long conditionCount = 0;
                    conditionCount++;
                    conditionCount++;
                    conditionCount++;
                    std::cout << "Count of comparisons: " << conditionCount << '\n';
                }
            }
            if (FeatureFlag::TIMER)
            {
                Timer::end();
                std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms" << std::endl;
            }

            return;
        }

        Node<T>* iterator = _first;

        for (int counter = 0; counter < position; counter++)
            iterator = &iterator->next();

        Node<T>* newNode = new Node<T>(data);
        Node<T>* previous = &iterator->previous();
        newNode->next(*iterator);
        newNode->previous(*previous);
        previous->next(*newNode);
        iterator->previous(*newNode);

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nINSERT operation log:\n";
            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCount = 0;
                assignmentCount++;
                assignmentCount++;
                assignmentCount += position;
                assignmentCount += 6;
                std::cout << "Count of assignments: " << assignmentCount << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCount = 0;
                conditionCount += 2;
                conditionCount += 2;
                conditionCount += position;
                conditionCount++;
                std::cout << "Count of comparisons: " << conditionCount << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    /**
     * Removes the last element of the list
    */
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

        _size--;

        Node<T>* oldLast = _last;
        _last = &_last->previous();
        delete oldLast;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nPOP operation log:\n";
            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCount = 0;
                assignmentCount++;
                assignmentCount += 2;
                std::cout << "Count of assignments: " << assignmentCount << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCount = 0;
                conditionCount++;
                std::cout << "Count of comparisons: " << conditionCount << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    /**
     * Removes an element of the list at a given position
     * @param position Position of the element to be removed (starting at 0)
    */
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


        if (position == _size)
        {
            this->pop();
            return;
        }

        _size--;

        if (position == 0)
        {
            Node<T>* oldFirst = _first;
            _first = &_first->next();

            if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
            {
                std::cout << "\nREMOVE operation log:\n";
                if (FeatureFlag::ASSIGNMENT_COUNTER)
                {
                    long assignmentCount = 0;
                    assignmentCount++;
                    assignmentCount += 2;
                    std::cout << "Count of assignments: " << assignmentCount << '\n';
                }
                if (FeatureFlag::CONDITION_COUNTER)
                {
                    long conditionCount = 0;
                    conditionCount += 3;
                    conditionCount++;
                    std::cout << "Count of comparisons: " << conditionCount << '\n';
                }
            }
            if (FeatureFlag::TIMER)
            {
                Timer::end();
                std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
            }
            delete oldFirst;
            return;
        }

        Node<T>* iterator = _first;

        for (int counter = 0; counter < position; counter++)
            iterator = &iterator->next();

        Node<T>* previous = &iterator->previous();
        Node<T>* next = &iterator->next();
        next->previous(*previous);
        previous->next(*next);
        delete iterator;

        if (FeatureFlag::ASSIGNMENT_COUNTER || FeatureFlag::CONDITION_COUNTER)
        {
            std::cout << "\nREMOVE operation log:\n";
            if (FeatureFlag::ASSIGNMENT_COUNTER)
            {
                long assignmentCount = 0;
                assignmentCount++;
                assignmentCount++;
                assignmentCount += position;
                assignmentCount += 4;
                std::cout << "Count of assignments: " << assignmentCount << '\n';
            }
            if (FeatureFlag::CONDITION_COUNTER)
            {
                long conditionCount = 0;
                conditionCount += 3;
                conditionCount++;
                conditionCount += position;
                conditionCount++;
                std::cout << "Count of comparisons: " << conditionCount << '\n';
            }
        }
        if (FeatureFlag::TIMER)
        {
            Timer::end();
            std::cout << "Elapsed time: " << Timer::elapsedTime() << "ms\n";
        }
    }

    /**
     * Looks for a given element if it is in the list
     * @param data Element to be found
     * @return Found element, if present
     * @throw Standard Exception if element can't be found
    */
    template <class T>
    T& List<T>::find(const T data)
    {
        for (T& item : *this)
            if (item == data)
                return item;

        throw std::exception();
    }
    /**
     * To be implemented. Searchs for an element at a given position
     * @param position Position of the desired element (starting at 0)
     * @throw Standard exception if position is out of bounds
    */
    template <class T>
    T& List<T>::findAt(int position) {
        std::cout << "To be implemented.\n";
    }

    /**
     * Uses the Selection Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::selectionSort()
    {
        std::cout << "To be implemented.\n";
    }
    /**
     * Uses the Insertion Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::insertionSort()
    {
        std::cout << "To be implemented.\n";
        // for (Node<T>* it = &_first->next(); it != &_last->next(); it++)
        // {
        //     Node<T>* currentElement = it;

        //     Node<T>* it2 = it;
        //     while(it2 != _first && *it2 <= it2->previous()) it2--;


        // }
        return this;
    }
    /**
     * To be implemented. Uses the Bubble Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::bubbleSort() {
        std::cout << "To be implemented.\n";
    }
    /**
     * To be implemented. Uses the Shell Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::shellSort() {
        std::cout << "To be implemented.\n";
    }
    /**
     * To be implemented. Uses the Quick Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::quickSort() {
        std::cout << "To be implemented.\n";
    }
    /**
     * TO be implemented. Uses the Merge Sort method to sort the list
     * @return Current list after sorting
    */
    template <class T>
    List<T>* List<T>::mergeSort() {
        std::cout << "To be implemented.\n";
    }

#pragma region Operator Overloads
    template <class T>
    ostream& operator<<(ostream& os, const List<T>& list)
    {
        if (list.size() < 1)
            return os << "Empty list.\n";

        for (T item : list)
            os << "[" << item << "]\n";

        return os;
    }
    template <class T>
    List<T>& List<T>::operator=(const List<T>& source)
    {
        if (this == &source)
            return *this;

        delete _first;
        delete _last;

        this->_size = source.size();

        if (source.size() == 1)
        {
            _first = _last = new Node<T>(source.first());
            return *this;
        }

        for (Node<T>& item : source)
            this->append(item.data());

        return *this;
    }
#pragma endregion
}
