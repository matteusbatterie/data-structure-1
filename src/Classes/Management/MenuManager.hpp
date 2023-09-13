#pragma once
#include <iostream>
#include "../Standard/KeyValuePair.hpp"
#include "../UserInterface/Menu/MainMenu.hpp"
#include "../UserInterface/Menu/InsertMenu.hpp"
#include "../UserInterface/Menu/RemoveMenu.hpp"

using namespace Standard;
using namespace UserInterface::Menu;

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
        string _sortMenuOption;
        string _loadMenuOption;

        string _selectedOption;

    public:
        MenuManager() {
            this->_mainMenu = nullptr;
            this->_insertMenu = nullptr;
            this->_removeMenu = nullptr;

            this->_listOption = "";
            this->_mainMenuOption = "";
            this->_insertMenuOption = "";
            this->_removeMenuOption = "";
            this->_sortMenuOption = "";
            this->_loadMenuOption = "";
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

        string sortMenuOption() const { return _sortMenuOption; }
        void sortMenuOption(const string option) { _sortMenuOption = option; }
    };
}
