#pragma once
#include <iostream>
#include "../UI.hpp"
#include "../../Standard/KeyValuePair.hpp"

using namespace Standard;
using std::string;

namespace Graphic::Menu
{
    class Menu : public UI
    {
    protected:
        KeyValuePair<int, string>* _options;
        KeyValuePair<int, string> _selectedOption;
        unsigned int _numberOfOptions;

    public:
        Menu() : UI() {
            this->_options = nullptr;
            this->_selectedOption = KeyValuePair<int, string>(-1, "");
            this->_numberOfOptions = 0;
        }
        virtual ~Menu() {
            if (this->_options) delete[] this->_options;
        }

        virtual void init() {
            clear();
            if (_numberOfOptions < 1) {
                std::cout << "This menu has no options.\n";
                std::cout << "Returning you to the previous menu in ";
                return;
            }

            for (int index = 0; index < _numberOfOptions; index++)
                std::cout << _options[index].key() << " - " << _options[index].value() << "\n";
            std::cout << ">> ";
        };
        virtual void clear() {
#ifdef _WIN64
            system("cls");
#endif
#ifdef __linux__
            system("clear");
#endif
        }
    };
}