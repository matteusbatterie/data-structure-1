#pragma once
#include "./Menu.hpp"

namespace UserInterface::Menu
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
        }
    };
}
