#pragma once
#include <iostream>
#include "../Standard/KeyValuePair.hpp"
#include "../Graphic/Menu/MainMenu.hpp"
#include "../Graphic/Menu/InsertMenu.hpp"
#include "../Graphic/Menu/RemoveMenu.hpp"

using namespace Standard;
using namespace Graphic::Menu;

namespace Management
{
    class MenuManager
    {
    private:
        MainMenu* _mainMenu;
        InsertMenu* _insertMenu;
        RemoveMenu* _removeMenu;

        string _listOption;
        string _mainMenuOption;
        string _insertMenuOption;
        string _removeMenuOption;

        std::string _selectedOption;

    public:
        MenuManager() {
            this->_mainMenu = nullptr;
            this->_insertMenu = nullptr;
            this->_removeMenu = nullptr;

            _listOption = "";
            _mainMenuOption = "";
            _insertMenuOption = "";
            _removeMenuOption = "";
        }
        ~MenuManager() {
            if (_mainMenu) delete _mainMenu;
            if (_insertMenu) delete _insertMenu;
            if (_removeMenu) delete _removeMenu;
        }

        string listOption() const { return _listOption; }
        void listOption(const string option) { _listOption = option; }

        string mainMenuOption() const { return _mainMenuOption; }
        void mainMenuOption(const string option) { _mainMenuOption = option; }

        string insertMenuOption() const { return _insertMenuOption; }
        void insertMenuOption(const string option) { _insertMenuOption = option; }

        string removeMenuOption() const { return _removeMenuOption; }
        void removeMenuOption(const string option) { _removeMenuOption = option; }
    };
}