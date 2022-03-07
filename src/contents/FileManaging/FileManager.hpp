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
        FileManager();
        ~FileManager();

        void read(string fileName) { _reader->read(fileName); }
        void write(string line, string fileName) { _writer->write(line, fileName); }
    };
}