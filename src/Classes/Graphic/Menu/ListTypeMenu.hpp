#pragma once
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class ListTypeMenu : public Menu
    {
        private:
        

        public:
        ListTypeMenu() {
            this->_numberOfOptions = 2;
            this->_options = new KeyValuePair<int, string>[_numberOfOptions]
            {
                KeyValuePair<int, string>(1, "Sequential List"),
                KeyValuePair<int, string>(2, "Linked List"),
                KeyValuePair<int, string>(0, "Quit")
            };
        }
        ~ListTypeMenu() { }

        void init() {
            Menu::init();
            clearBuffer();
            while(_selectedOption.key() != 0)
            {
                switch (getchar())
                {
                case '1':
                    _selectedOption = _options[0];
                    break;
                case '2':
                    _selectedOption = _options[1];
                    break;
                case '0':
                    _selectedOption = _options[2];
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
