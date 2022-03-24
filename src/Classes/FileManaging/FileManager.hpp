#pragma once
#include <iostream>
#include "FileReader.hpp"
#include "FileWriter.hpp"
#include "../Standard/Array.hpp"
#include "../Sequential/List.hpp"
#include "../Linked/List.hpp"
#include "../Entities/Person.hpp"

using std::string;
using namespace Standard::Query;
using namespace DataStructure::Query;
using namespace Entities;

namespace FileConfiguration
{
    using Util::FileReader;
    using Util::FileWriter;

    class FileManager
    {
        private:
        FileReader* _reader;
        FileWriter* _writer;

        public:
        FileManager() {
            this->_reader = new FileReader();
            this->_writer = new FileWriter();
        }
        ~FileManager() {
            delete (this->_reader);
            delete (this->_writer);
        }

        string read(string fileName) { return _reader->read(fileName); }
        Array<string> readAsArray(string fileName) { return _reader->readAsArray(fileName); }
        Sequential::List<Person> readAsListSequential(string fileName) { return _reader->readAsListSequential(fileName); }
        Linked::List<Person> readAsListLinked(string fileName) { return _reader->readAsListLinked(fileName); }

        void write(string line, string fileName) { _writer->write(line, fileName); }
    };
}
