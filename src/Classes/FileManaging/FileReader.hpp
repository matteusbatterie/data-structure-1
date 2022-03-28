#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "../Standard/Array.hpp"
#include "../Sequential/List.hpp"
#include "../Linked/List.hpp"
#include "../Entities/Person.hpp"

using std::string;
using namespace Standard::Query;
using namespace DataStructure::Query;
using namespace Entities;

namespace FileConfiguration::Util
{
    const string PATH = "./database/";

    class FileReader
    {
    public:
        FileReader() {}
        ~FileReader() {}

        string read(const string fileName);
        Array<string> readAsArray(const string fileName);
        Sequential::List<Person> readAsListSequential(const string fileName);
        Linked::List<Person> readAsListLinked(const string fileName);
    };

    string FileReader::read(const string fileName)
    {
        ifstream file;
        stringstream buffer;

        file.open(PATH + fileName);
        buffer << file.rdbuf();

        return buffer.str();
    }

    Array<string> FileReader::readAsArray(const string fileName) {
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
        else cout << "Unable to open file.\n";

        return array;
    }

    Sequential::List<Person> FileReader::readAsListSequential(const string fileName)
    {
        Sequential::List<Person> list = Sequential::List<Person>();
        ifstream file;
        file.open(PATH + fileName);

        if (!file.is_open()) {
            cout << "Unable to open file.\n";
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

    Linked::List<Person> FileReader::readAsListLinked(const string fileName) {
        Linked::List<Person> list = Linked::List<Person>();
        ifstream file;
        file.open(PATH + fileName);

        if (!file.is_open()) {
            cout << "Unable to open file.\n";
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
}
