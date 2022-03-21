#include <string>
#include <iostream>

using namespace std;

namespace Entities
{
    class Person
    {
    private: 
        unsigned int _id;
        string _name;

    public:
        Person(const unsigned int id = 0, const string name = "") {
            this->_id = id;
            this->_name = name;
        }
        ~Person() { }

        unsigned int id() const { return this->_id; }
        void id(const unsigned int id) { this->_id = id; }

        string name() const { return this->_name; }
        void name(const string name) { this->_name = name; }

        friend ostream& operator<<(ostream& os, const Person& person) {
            string output = person.name() + ", " + to_string(person.id());
            return os << output;
        }
     };
}