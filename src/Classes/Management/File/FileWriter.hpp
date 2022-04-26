#include <iostream>
#include <fstream>

using std::string;

namespace Management::File
{
    class FileWriter
    {
    private:

    public:
        FileWriter() {}
        ~FileWriter() {}

        void write(string fileName, string line) {
            std::ofstream myfile(fileName + ".txt");
            if (myfile.is_open())
            {
                myfile << line << '\n';
                myfile.close();
            }
            else std::cout << "Unable to open file\n";
        }
        void write(string fileName, Sequential::List<Person> list) {
            for (int index = 0; index < list.size(); index++)
            {
                string line = list._first[index].id() + ", " + list._first[index].name();
                write(fileName, line);
            }
        }
        void write(string fileName, Linked::List<Person> list);
    };
}