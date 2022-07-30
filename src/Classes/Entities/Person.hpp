#pragma once
#include <string>
#include <iostream>

using std::string;
using std::to_string;
using std::ostream;

namespace Entities
{
    class Person
    {
    private:
        unsigned long _id;
        string _name;

    public:
        Person(const Person& copy) {
            this->_id = copy._id;
            this->_name = copy._name;
        }
        Person(const unsigned long id = 0, const string name = "") {
            this->_id = id;
            this->_name = name;
        }
        ~Person() { }

        unsigned long id() const { return this->_id; }
        void id(const unsigned long id) { this->_id = id; }

        string name() const { return this->_name; }
        void name(const string name) { this->_name = name; }

        friend ostream& operator<<(ostream& os, const Person& person) {
            const string personName = person.name();
            const string personIdStr = to_string(person.id());
            const string output = personName + ", " + personIdStr;
            return os << output;
        }

        Person& operator=(const Person& copy) {
            this->_id = copy._id;
            this->_name = copy._name;

            return *this;
        }

        bool operator==(const Person& comparison) {
            return this->id() == comparison.id();
        }
        bool operator<(const Person& comparison) {
            return this->id() < comparison.id();
        }
        bool operator<=(const Person& comparison) {
            return this->id() <= comparison.id();
        }
        bool operator>(const Person& comparison) {
            return this->id() > comparison.id();
        }
        bool operator>=(const Person& comparison) {
            return this->id() >= comparison.id();
        } 
    };
}