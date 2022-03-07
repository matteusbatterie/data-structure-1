#include "Node.hpp"

using DataStructure::Query::Linked::Util::Node;

namespace DataStructure
{
    namespace Query
    {
        namespace Linked
        {
            template <class T>
            class ListManager
            {
                private:
                Node<T>* _first;
                Node<T>* _last;
                
                public:
                ListManager() {
                    this->_first = nullptr;
                    this->_last = nullptr;
                }
                ~ListManager() {}

                Node<T>* first() const { return this->_first; }

                Node<T>* last() const { return this->_last; }

                void append(T data) {}
                void insert(T data, int position) {}

                void pop() {}
                void remove(int position) {}
            };
        }
    }
}