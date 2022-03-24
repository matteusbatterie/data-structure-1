#pragma once

namespace DataStructure::Query::Linked::Util
{
    template <class T>
    class Node
    {
    private:
        Node<T>* _previous;
        Node<T>* _next;

    public:
        Node() {
            this->_previous = nullptr;
            this->_next = nullptr;
        }
        ~Node() {}

        Node<T>* previous() const { return this->_previous; }
        void previous(Node* newPrevious) { this->_previous = newPrevious; }

        Node<T>* next() const { return this->_previous; }
        void next(Node* newNext) { this->_next = newNext; }
    };
}
