#pragma once
#include <iostream>
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class SaveMenu : public Menu
    {
        private:
        std::string _fileName;

        public:
        SaveMenu() {
            this->_fileName = "";
        }
        ~SaveMenu() { }

        std::string fileName() const { return _fileName; }

        void init() {
             do
            {
                std::cout << "Please, enter the name of the file:\n";
                Menu::read();
            } while(!isValidFileName(_input));

            _fileName = _input;
        }

        bool isValidFileName(std::string line) {
            for(std::string::const_iterator it = line.begin(); it != line.end(); it++) 
                if (!std::iswalnum(*it)) {
                    std::cout << "Invalid value\n";
                    return false;
                }
            
            return true;
        }
    };
}
