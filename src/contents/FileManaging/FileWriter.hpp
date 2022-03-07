#include <iostream>
#include <fstream>

using namespace std;

namespace FileConfiguration
{
    namespace Util
    {
        class FileWriter
        {
            private:

            public:
            FileWriter() {}
            ~FileWriter() {}

            void write(string line, string fileName) {
                ofstream myfile (fileName + ".txt");
                if (myfile.is_open())
                {
                    myfile << line << endl;
                    myfile.close();
                }
                else cout << "Unable to open file";
            }
        };
    }
}