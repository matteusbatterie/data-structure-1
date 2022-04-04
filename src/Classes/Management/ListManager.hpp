#pragma once
#include "../Linked/List.hpp"
#include "../Sequential/List.hpp"
#include "../Entities/Person.hpp"

using namespace DataStructure::Query;
using namespace Entities;

namespace Management
{
    class ListManager
    {
    private:
        Sequential::List<Person>* _sequentialList;
        Linked::List<Person>* _linkedList;

    public:
        ListManager() {
            this->_sequentialList = nullptr;
            this->_linkedList = nullptr;
        }
        ~ListManager() {}

        Sequential::List<Person>* sequential() const { return _sequentialList; }
        Linked::List<Person>* linked() const { return _linkedList; }
    };
}
