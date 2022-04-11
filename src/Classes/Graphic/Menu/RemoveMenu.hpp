#pragma once
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class RemoveMenu : public Menu {
    private:

    public:
        RemoveMenu() : Menu() {
            this->_numberOfOptions = 4;
            this->_options = new KeyValuePair<int, string>[_numberOfOptions]
            {
                KeyValuePair<int, string>(1, "Remove at begin"),
                KeyValuePair<int, string>(2, "Remove at end"),
                KeyValuePair<int, string>(3, "Remove at position"),
                KeyValuePair<int, string>(0, "Quit")
            };
        }
        ~RemoveMenu() override {
            delete[] this->_options;
        }

        void init() {
            while (_selectedOption.key() != 0)
            {
                Menu::init();
                clearBuffer();
                switch (getchar())
                {
                case '1':
                    _selectedOption = _options[0];
                    break;
                case '2':
                    _selectedOption = _options[1];
                    break;
                case '3':
                    _selectedOption = _options[2];
                    break;
                case '0':
                    _selectedOption = _options[3];
                    return;
                    break;
                default:
                    _selectedOption = KeyValuePair<int, string>();
                    std::cout << "Invalid option.\n";
                    break;
                }
            }
        }
    };
}
