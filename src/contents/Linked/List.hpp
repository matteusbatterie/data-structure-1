#include "ListManager.hpp"

using DataStructure::Query::Linked::ListManager;

namespace DatauStructure
{
    namespace Query
    {
        namespace Linked
        {
            template <class T>
            class List
            {
                private:
                ListManager<T>* _manager;
                unsigned int _size;
                
                public:
                List() { 
                    this->_manager = new ListManager<T>(); 
                    this->_size = 0;    
                }
                ~List() { delete (this->_manager); }

                unsigned int size() const { return this->_size; }
                void size(const int newSize) { this->_size = newSize; }

                void append(T data) { _manager->append(data); }
                void insert(T data, int position) { _manager->insert(data, position); }

                void pop() { _manager->pop(); }
                void remove(int position) { _manager->remove(position); }

                void find(T data);
                void findAt(int position);
            };
        }
    }
}