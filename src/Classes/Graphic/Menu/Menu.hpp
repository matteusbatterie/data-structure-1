#pragma once
#include "../UI.hpp"
#include "../../Standard/KeyValuePair.hpp"

using namespace Standard;
using std::string;

namespace Graphic::Menu
{
    class Menu : public UI
    {
    protected:
        std::string _input;

        KeyValuePair<int, std::string>* _options;
        KeyValuePair<int, std::string> _selectedOption;
        unsigned int _numberOfOptions;

    public:
        Menu() : UI() {
            this->_input = "";

            this->_options = nullptr;
            this->_selectedOption = KeyValuePair<int, std::string>(-1, "");
            this->_numberOfOptions = 0;
        }
        virtual ~Menu() {
            if (this->_options) delete[] this->_options;
        }

        std::string command() const { return _selectedOption.value(); }

        virtual void init() {
            clear();
            if (_numberOfOptions < 1) {
                std::cout << "This menu has no options.\n";
                std::cout << "Returning you to the previous menu in ";
                return;
            }

            for (int index = 0; index < _numberOfOptions; index++)
                std::cout << _options[index].key() << " - " << _options[index].value() << "\n";
        };

        virtual void read() {
            std::cout << ">> ";
            std::cin >> _input;
        }

        protected:
        virtual void clear() {    
#ifdef _WIN64
            system("cls");
#endif
#ifdef __linux__
            system("clear");
#endif
        }
        virtual void clearBuffer() {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    };
}
