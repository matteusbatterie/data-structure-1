#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace FileConfiguration
{
    namespace Util
    {
        class FileReader
        {
            private:

            public:
            FileReader() {}
            ~FileReader() {}

            void read(string fileName) {
                string line;
                ifstream myfile(fileName + ".txt");
                if (myfile.is_open())
                {
                    while (getline(myfile,line))
                        cout << line << '\n';

                    myfile.close();
                }
                else cout << "Unable to open file"; 
            }
        };
    }
}