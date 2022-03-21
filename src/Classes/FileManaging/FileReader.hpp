#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "./../Array.hpp"

using namespace std;
using namespace Standard;

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

            for(unsigned int index = 0;
                index < array.size();
                index++)
            {

            }

            return array;
        }
    };
}