#pragma once
#include "./Menu.hpp"

namespace Graphic::Menu
{
    class SearchMenu : public Menu
    {
        private:

        public:
        SearchMenu() : Menu() {

        }
        ~SearchMenu() {}

        void init() {
            std::cout << "Please, enter the ID of the person you want to find: \n";
            std::cout << ">> ";

            getchar();
        }
    };
}
