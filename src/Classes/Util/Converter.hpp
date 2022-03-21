#pragma once
#include <string>
#include <bits/stdc++.h>

using namespace std;

namespace Utilities
{
    class Converter
    {
    public:
        Converter() {}
        ~Converter() {}

        static string toString(const auto& value)
        {
            const string typeStr = typeid(value).name();
            if (typeStr.find("string") != string::npos) return value;

            //return to_string(value);
            return value;
        }
    };
}
