#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "../Standard/Array.hpp"
#include "../Sequential/List.hpp"
#include "../Linked/List.hpp"
#include "../Entities/Person.hpp"

using namespace std;
using namespace Standard::Query;
using namespace DataStructure::Query;
using namespace Entities;

namespace FileConfiguration::Util
{
    class FileReader
    {
    private:
        const string PATH = "./database/";

    public:
        FileReader() {}
        ~FileReader() {}

        string read(const string fileName) {
            ifstream file;
            stringstream buffer;

            file.open(PATH + fileName);
            buffer << file.rdbuf();

            return buffer.str();
        }
        
        Array<string> readAsArray(const string fileName) {
            Array<string> array;
            ifstream file;
            file.open(PATH + fileName);

            if (file.is_open())
            {
                string line;
                while (getline(file, line))
                    array.insert(line);

                file.close();
            }
            else cout << "Unable to open file." << endl;

            for (unsigned int index = 0;
                index < array.size();
                index++)
            {

            }

            return array;
        }

        Sequential::List<Person> readAsListSequential(const string fileName) {
            Sequential::List<Person> list = Sequential::List<Person>();
            ifstream file;
            file.open(PATH + fileName);

            if (!file.is_open()) {
                cout << "Unable to open file." << endl;
                return list;
            }

            while (file.good() && !file.eof())
            {
                string personName;
                string personIdStr;

                getline(file, personName, ',');
                getline(file, personIdStr);

                if (file.eof())
                    break;

                Person person = Person{
                    stoul(personIdStr, nullptr, 0),
                    personName
                };
                list.append(person);
            }

            file.close();
            return list;
        }

        Linked::List<Person> readAsListLinked(const string fileName) {
            // to be implemented
        }
    };
}