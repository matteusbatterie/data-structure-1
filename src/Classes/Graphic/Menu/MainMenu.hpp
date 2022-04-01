#pragma once
#include <iostream>
#include "./Menu.hpp"
#include "./InsertMenu.hpp"
#include "./RemoveMenu.hpp"

using std::string;

namespace Graphic::Menu
{
    class MainMenu : public Menu
    {
    private:
        InsertMenu* _insertMenu;
        RemoveMenu* _removeMenu;

    public:
        MainMenu() : Menu() {
            this->_insertMenu = nullptr;
            this->_removeMenu = nullptr;
            this->_numberOfOptions = 7;
            this->_options = new KeyValuePair<int, string>[_numberOfOptions]
            {
                KeyValuePair<int, string>(1, "Insert"),
                    KeyValuePair<int, string>(2, "Remove"),
                    KeyValuePair<int, string>(3, "Search"),
                    KeyValuePair<int, string>(4, "Display"),
                    KeyValuePair<int, string>(5, "Save"),
                    KeyValuePair<int, string>(6, "Load"),
                    KeyValuePair<int, string>(0, "Quit")
            };
        }
        ~MainMenu() {
            delete[] this->_options;
        }

        void init() {
            Menu::init();

            switch (getchar())
            {
            case '1':
                _selectedOption = KeyValuePair<int, string>(_options[0]);
                _insertMenu = new InsertMenu();
                _insertMenu->init();
                delete _insertMenu;
                break;
            case '2':
                _selectedOption = KeyValuePair<int, string>(_options[1]);
                _removeMenu = new RemoveMenu();
                _removeMenu->init();
                delete _removeMenu;
                break;
            case '3':
                _selectedOption = KeyValuePair<int, string>(_options[2]);
                break;
            case '4':
                _selectedOption = KeyValuePair<int, string>(_options[3]);
                break;
            case '5':
                _selectedOption = KeyValuePair<int, string>(_options[4]);
                break;
            case '6':
                _selectedOption = KeyValuePair<int, string>(_options[5]);
                break;
            case '0':
                _selectedOption = KeyValuePair<int, string>(_options[6]);
                break;
            default:
                _selectedOption = KeyValuePair<int, string>();
                std::cout << "Invalid option.\n";
                break;
            }
        }
    };
}