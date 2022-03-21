#pragma once
#include "FileReader.hpp"
#include "FileWriter.hpp"
#include <iostream>

using std::string;

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
        List<string> readAsList(string fileName) { }

        void write(string line, string fileName) { _writer->write(line, fileName); }
    };
}