#pragma once
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class SearchMenu : public Menu
    {
        private:
        long _id;

        public:
        SearchMenu() : Menu() {
            this->_id = -1;
        }
        ~SearchMenu() { }

        long id() const { return _id; }

        void init() {
            do
            {
                std::cout << "Please, enter the ID of the person you want to find: \n";
                Menu::read();
            } while(!isValidId(_input));

            _id = stoul(_input);
        }

        private:
        bool isValidId(std::string idStr) {
            for(std::string::const_iterator it = idStr.begin(); it != idStr.end(); it++) 
                if (!std::isdigit(*it)) {
                    std::cout << "Invalid value\n";
                    return false;
                }

            return true;
        }
    };
}
