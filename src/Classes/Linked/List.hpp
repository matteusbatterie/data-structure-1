#pragma once
#include "./Node.hpp"

using std::ostream;

namespace DataStructure::Query::Linked
{
    template <class T>
    class List
    {
    private:
        Node<T> *_first;
        Node<T> *_last;
        unsigned long _size;

    public:
        List(const List<T> &copy)
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
            for (Node<T> *iterator = _first; iterator != _last; iterator = &(iterator->next()))
                delete iterator;
        }

        unsigned long size() const { return this->_size; }
        T &first() const { return _first->data(); }
        T &last() const { return _last->data(); }

        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        T &find(const T data);
        void findAt(int position);

        void print()
        {
            for (Node<T> *iterator = _first; iterator != &_last->next(); iterator = &(iterator->next()))
                std::cout << iterator->data() << '\n';
        }

        Node<T> &begin() const { return *_first; }
        Node<T> &end() const { return _last->next(); }

        template <class E>
        friend ostream &operator<<(ostream &os, const List<E> &list);
        List<T> &operator=(const List<T> &source);
    };

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

        Node<T> *newNode = new Node<T>(data);
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
            Node<T> *newNode = new Node<T>(data);
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

        Node<T> *iterator = _first;

        for (int counter = 0; counter < position; counter++)
            iterator = &iterator->next();

        Node<T> *newNode = new Node<T>(data);
        Node<T> *previous = &iterator->previous();
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

        Node<T> *oldLast = _last;
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
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
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

        if (position == _size)
        {
            this->pop();
            return;
        }

        _size--;

        if (position == 0)
        {
            Node<T> *oldFirst = _first;
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

        Node<T> *iterator = _first;

        for (int counter = 0; counter < position; counter++)
            iterator = &iterator->next();

        Node<T> *previous = &iterator->previous();
        Node<T> *next = &iterator->next();
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
                assignmentCount += ;
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

    template <class T>
    T &List<T>::find(const T data)
    {
        for (T &item : *this)
            if (item == data) return item;
    }

    template <class T>
    ostream &operator<<(ostream &os, const List<T> &list)
    {
        if (list.size() < 1)
            return os << "Empty list.\n";

        for (T item : list)
            os << "[" << item << "]\n";

        return os;
    }

    template <class T>
    List<T> &List<T>::operator=(const List<T> &source)
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

        for (Node<T> &item : source)
            this->append(item.data());

        return *this;
    }
}
