#pragma once
#include "./Node.hpp"

using std::ostream;

namespace DataStructure::Query::Linked
{
    template <class T>
    class List
    {
    private:
        Node<T>* _first;
        Node<T>* _last;
        unsigned long _size;

    public:
        List(const List<T>& copy) {
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
            for (T item : copy)
                this->append(item);
        }
        List() {
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
        }
        ~List() {
            for (Node<T>* iterator = _first; iterator != _last; iterator = &(iterator->next()))
                delete iterator;
        }

        unsigned long size() const { return this->_size; }
        T& first() const { return _first->data(); }
        T& last() const { return _last->data(); }


        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        T& find(const T data);
        void findAt(int position);

        List<T>* selectionSort();
        List<T>* insertionSort();


        void print() {
            for (Node<T>* iterator = _first; iterator != _last; iterator = &(iterator->next()))
                std::cout << iterator->data() << '\n';
        }

        Node<T>& begin() const { return *_first; }
        Node<T>& end() const { return _last->next(); }

        template <class E>
        friend ostream& operator<<(ostream& os, const List<E>& list);
        List<T>& operator=(const List<T>& source);
    };

    template <class T>
    void List<T>::append(T data)
    {
        _size++;

        if (!_first) {
            _first = _last = new Node<T>(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->previous(*_last);
        _last->next(*newNode);
        _last = newNode;
    }

    template <class T>
    void List<T>::insert(T data, int position)
    {
        if (position > _size || position < 0) {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        if (position == _size) {
            append(data);
            return;
        }

        _size++;

        if (!_first) {
            _first = _last = new Node<T>(data);
            return;
        }

        if (position == 0) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next(*_first);
            _first->previous(*newNode);
            _first = newNode;
            return;
        }

        Node<T>* iterator = _first;
        for (int counter = 0; counter < position - 1; counter++)
            iterator = &iterator->next();

        Node<T>* newNode = new Node<T>(data);
        Node<T>* previous = &iterator->previous();
        newNode->next(*iterator);
        newNode->previous(*previous);
        previous->next(*newNode);
        iterator->previous(*newNode);
    }

    template <class T>
    void List<T>::pop()
    {
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        _size--;

        Node<T>* oldLast = _last;
        _last = &_last->previous();
        delete oldLast;
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

        if (position == _size) {
            this->pop();
            return;
        }

        _size--;
        if (position == 0) {
            Node<T>* oldFirst = _first;
            _first = &_first->next();
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
    }

    template <class T>
    T& List<T>::find(const T data)
    {
        for (T& item : *this)
            if (item == data) return item;
    }

    template <class T>
    List<T>* List<T>::selectionSort()
    {

    }
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


    template <class T>
    ostream& operator<<(ostream& os, const List<T>& list)
    {
        if (list.size() < 1) return os << "Empty list.\n";

        for (T item : list)
            os << "[" << item << "]\n";

        return os;
    }

    template <class T>
    List<T>& List<T>::operator=(const List<T>& source)
    {
        if (this == &source) return *this;

        delete _first;
        delete _last;

        this->_size = source.size();

        if (source.size() == 1) {
            _first = _last = new Node<T>(source.first());
            return *this;
        }

        for (Node<T>& item : source)
            this->append(item.data());

        return *this;
    }
}
