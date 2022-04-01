#pragma once
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class InsertMenu : public Menu {
    private:

    public:
        InsertMenu() : Menu() {
            this->_numberOfOptions = 4;
            this->_options = new KeyValuePair<int, string>[_numberOfOptions]
            {
                KeyValuePair<int, string>(1, "Insert at begin"),
                    KeyValuePair<int, string>(2, "Insert at end"),
                    KeyValuePair<int, string>(3, "Insert at position"),
                    KeyValuePair<int, string>(0, "Quit")
            };
        }
        ~InsertMenu() {
            delete[] this->_options;
        }

        void init() {
            Menu::init();

            fflush(stdin);
            switch (getchar())
            {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '0':
                _selectedOption = KeyValuePair<int, string>(_options[4]);
                return;
                break;
            default:
                _selectedOption = KeyValuePair<int, string>();
                std::cout << "Invalid option.\n";
                break;
            }
        }
    };
}
