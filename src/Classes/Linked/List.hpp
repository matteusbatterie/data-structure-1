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
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        a++;
        _size++;

        c++;
        if (!_first) {
            a++;
            _first = _last = new Node<T>(data);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "\nAPPEND operation log:\n";
            std::cout << "Count of assignments: " << a << '\n';
            std::cout << "Count of comparisons: " << c << '\n';
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        newNode->previous(*_last);
        _last->next(*newNode);
        _last = newNode;
        a += 4;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "\nAPPEND operation log:\n";
        std::cout << "Count of assignments: " << a << '\n';
        std::cout << "Count of comparisons: " << c << '\n';
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    void List<T>::insert(T data, int position)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        c++;
        if (position > _size || position < 0) {
            std::cout << "Invalid range for insertion.\n";
            return;
        }

        c++;
        if (position == _size) {
            append(data);
            return;
        }

        _size++;
        a++;

        c++;
        if (!_first) {
            _first = _last = new Node<T>(data);
            a++;
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "\nINSERT operation log:\n";
            std::cout << "Count of assignments: " << a << '\n';
            std::cout << "Count of comparisons: " << c << '\n';
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;

            return;
        }

        c++;
        if (position == 0) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next(*_first);
            _first->previous(*newNode);
            _first = newNode;
            a += 4;
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "\nINSERT operation log:\n";
            std::cout << "Count of assignments: " << a << '\n';
            std::cout << "Count of comparisons: " << c << '\n';
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;

            return;
        }

        a++;
        Node<T>* iterator = _first;

        for (int counter = 0; counter < position - 1; counter++)
        {
            c++;
            a++;
            iterator = &iterator->next();
        }
        c++;

        Node<T>* newNode = new Node<T>(data);
        Node<T>* previous = &iterator->previous();
        newNode->next(*iterator);
        newNode->previous(*previous);
        previous->next(*newNode);
        iterator->previous(*newNode);
        a += 6;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "\nINSERT operation log:\n";
        std::cout << "Count of assignments: " << a << '\n';
        std::cout << "Count of comparisons: " << c << '\n';
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    void List<T>::pop()
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        c++;
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        a++;
        _size--;

        Node<T>* oldLast = _last;
        _last = &_last->previous();
        delete oldLast;

        a += 2;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "\nPOP operation log:\n";
        std::cout << "Count of assignments: " << a << '\n';
        std::cout << "Count of comparisons: " << c << '\n';
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    void List<T>::remove(int position)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        c++;
        if (position > _size || position < 0) {
            std::cout << "Invalid range for remotion.\n";
            return;
        }

        c++;
        if (_size == 0) {
            std::cout << "There are no elements to be removed.\n";
            return;
        }

        c++;
        if (position == _size) {
            this->pop();
            return;
        }

        a++;
        _size--;

        c++;
        if (position == 0) {
            Node<T>* oldFirst = _first;
            _first = &_first->next();
            a += 2;
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "\nREMOVE operation log:\n";
            std::cout << "Count of assignments: " << a << '\n';
            std::cout << "Count of comparisons: " << c << '\n';
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
            delete oldFirst;
            return;
        }

        a++;
        Node<T>* iterator = _first;

        for (int counter = 0; counter < position; counter++)
        {
            c++;
            a++;
            iterator = &iterator->next();
        }
        c++;

        Node<T>* previous = &iterator->previous();
        Node<T>* next = &iterator->next();
        next->previous(*previous);
        previous->next(*next);
        delete iterator;

        a += 4;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "\nREMOVE operation log:\n";
        std::cout << "Count of assignments: " << a << '\n';
        std::cout << "Count of comparisons: " << c << '\n';
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
    }

    template <class T>
    T& List<T>::find(const T data)
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        int a = 0, c = 0;

        for (T& item : *this)
        {
            c++;
            if (item == data) {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                std::cout << "\nFIND operation log:\n";
                std::cout << "Count of assignments: " << a << '\n';
                std::cout << "Count of comparisons: " << c << '\n';
                std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
                return item;
            }
            c++;
        }
        c++;

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "\nFIND operation log:\n";
        std::cout << "Count of assignments: " << a << '\n';
        std::cout << "Count of comparisons: " << c << '\n';
        std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "ms" << std::endl;
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
