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
            this->_sequentialList = new Sequential::List<Person>();
            this->_linkedList = new Linked::List<Person>();
        }
        ~ListManager() {
            if(_sequentialList) delete _sequentialList;
            if(_linkedList) delete _linkedList;
        }

        Sequential::List<Person>* sequential() const { return _sequentialList; }
        void sequential(const Sequential::List<Person> list) { _sequentialList = new Sequential::List<Person>(list); }

        Linked::List<Person>* linked() const { return _linkedList; }
        void linked(const Linked::List<Person> list) { _linkedList = new Linked::List<Person>(list); }
    };
}
