#pragma once
#include <string>

using namespace std;

namespace Utilities
{
    class Looper
    {
    public:
        Looper() {}
        ~Looper() {}

        static string* copyArray(string* source, unsigned int size)
        {
            string* newArray = new string[size];
            for (unsigned int index = 0;
                index < size;
                index++)
            {
                newArray[index] = source[index];
            }

            return newArray;
        }
    };
}
