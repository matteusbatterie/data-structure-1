#pragma once
#include "./Menu.hpp"
#include "./InsertMenu.hpp"
#include "./RemoveMenu.hpp"

using std::string;

namespace Graphic::Menu
{
    class MainMenu : public Menu
    {
    private:

    public:
        MainMenu() : Menu() {
            this->_numberOfOptions = 7;
            this->_options = new KeyValuePair<int, std::string>[_numberOfOptions]
            {
                KeyValuePair<int, std::string>(1, "Insert"),
                KeyValuePair<int, std::string>(2, "Remove"),
                KeyValuePair<int, std::string>(3, "Search"),
                KeyValuePair<int, std::string>(4, "Display"),
                KeyValuePair<int, std::string>(5, "Save"),
                KeyValuePair<int, std::string>(6, "Load"),
                KeyValuePair<int, std::string>(0, "Quit")
            };
        }
        virtual ~MainMenu() { }

        void init() {
            while (_selectedOption.key() != 0)
            {
                Menu::init();
                fflush(stdin);
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
                case '4':
                    _selectedOption = _options[3];
                    break;
                case '5':
                    _selectedOption = _options[4];
                    break;
                case '6':
                    _selectedOption = _options[5];
                    break;
                case '0':
                    _selectedOption = _options[6];
                    break;
                default:
                    _selectedOption = KeyValuePair<int, std::string>();
                    std::cout << "Invalid option.\n";
                    break;
                }
            }
        }
    };
}