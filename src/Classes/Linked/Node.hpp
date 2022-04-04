#pragma once

namespace DataStructure::Query::Linked
{
    template <class T>
    class Node
    {
    private:
        int _position;
        T* _data;
        Node<T>* _previous;
        Node<T>* _next;

    public:
        Node(const T& data, const int position = -1) {
            this->_position = position;
            this->data(data);
            this->_previous = nullptr;
            this->_next = nullptr;
        }
        Node(const Node<T>& copy) {
            if (&copy == nullptr)
            {
                _data = nullptr;
                _previous = _next = nullptr;
                return;
            }

            this->data(copy.data());
            this->previous(copy.previous());
            this->next(copy.next());
        }
        Node(T* data = nullptr, Node<T>* previous = nullptr, Node<T>* next = nullptr) {
            this->_data = data;
            this->_previous = previous;
            this->_next = next;
        }
        ~Node() {
            if(_data) 
                delete _data;
        }

        int position() const { return _position; }
        void position(const int position) { _position = position; }

        T& data() const { return *(this->_data); }
        void data(const T& data) { this->_data = new T(data); }

        Node<T>& previous() const { return *(this->_previous); }
        void previous(Node<T>& previous) { this->_previous = &previous; }

        Node<T>& next() const { return *(this->_next); }
        void next(Node<T>& next) { this->_next = &next; }

        T& operator*();
        Node<T>& operator=(const Node<T>& source);
        bool operator!=(const Node<T>& comparable);
        Node<T>& operator++();
        Node<T> operator++(int);
        Node<T>& operator--();
        Node<T> operator--(int);
    };

    template <class T>
    T& Node<T>::operator*()
    {
        return this->data();
    }

    template <class T>
    Node<T>& Node<T>::operator=(const Node<T>& source)
    {
        if (this == &source) return *this;

        if (&source == nullptr) {
            _data = nullptr;
            _previous = _next = nullptr;
            return *this;
        };

        this->data(source.data());
        this->previous(source.previous());
        this->next(source.next());

        return *this;
    }

    template <class T>
    bool Node<T>::operator!=(const Node<T>& comparable)
    {
        if (!&comparable)
            return _data != nullptr
            || _previous != nullptr || _next != nullptr;

        return _data != comparable._data
            || _previous != comparable._previous
            || _next != comparable._next;
    }

    template <class T>
    Node<T>& Node<T>::operator++()
    {
        *this = *_next;
        return *this;
    }
    template <class T>
    Node<T> Node<T>::operator++(int)
    {
        Node<T>* temp = this;
        *this = *(this->next());
        return *temp;
    }

    template <class T>
    Node<T>& Node<T>::operator--()
    {
        this = this->previous();
        return *this;
    }
    template <class T>
    Node<T> Node<T>::operator--(int)
    {
        Node<T>* temp = this;
        *this = *(this->previous());
        return *temp;
    }
}
