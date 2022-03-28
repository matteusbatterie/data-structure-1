#pragma once
#include "./Node.hpp"

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
            this->_first = new Node<T>(copy.first());
            this->_last = new Node<T>(copy.last());
            this->_size = copy.size();
        }
        List() {
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
        }
        ~List() {
            for (Node<T>* iterator = _first;
                iterator != _last;
                iterator = &(iterator->next()))
                delete iterator;
        }

        unsigned long size() const { return this->_size; }
        T& first() const { return _first->data(); }
        T& last() const { return _last->data(); }


        void append(T data);
        void insert(T data, int position);

        void pop();
        void remove(int position);

        void find(T data);
        void findAt(int position);


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
