#pragma once
#include <iostream>
#include "./Menu.hpp"
#include "../../Standard/KeyValuePair.hpp"
#include "../../Constants/FilesNames.hpp"

using Standard::KeyValuePair;
using namespace Constants::PeopleFilesNames;

namespace Graphic::Menu
{
    class LoadMenu : public Menu
    {
        private:

        public:
        LoadMenu() {
            this->_numberOfOptions = 7;
            this->_options = new KeyValuePair<int, std::string>[_numberOfOptions]
            {
                KeyValuePair<int, std::string>(1, NAME_AND_ID_10.name),
                KeyValuePair<int, std::string>(2, NAME_AND_ID_50.name),
                KeyValuePair<int, std::string>(3, NAME_AND_ID_100.name),
                KeyValuePair<int, std::string>(4, NAME_AND_ID_1K.name),
                KeyValuePair<int, std::string>(5, NAME_AND_ID_10K.name),
                KeyValuePair<int, std::string>(6, NAME_AND_ID_100M.name),
                KeyValuePair<int, std::string>(0, "Quit")
            };
         }
        ~LoadMenu() { }

        void init() {
            Menu::init();
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
                case '7':
                    _selectedOption = _options[6];
                    break;
                case '0':
                    _selectedOption = _options[7];
                    return;
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
