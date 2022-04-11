#pragma once
#include <iostream>
#include "../Standard/KeyValuePair.hpp"
#include "../Graphic/Menu/ListTypeMenu.hpp"
#include "../Graphic/Menu/MainMenu.hpp"
#include "../Graphic/Menu/InsertMenu.hpp"
#include "../Graphic/Menu/RemoveMenu.hpp"
#include "../Graphic/Menu/SearchMenu.hpp"
#include "../Graphic/Menu/SaveMenu.hpp"
#include "../Graphic/Menu/LoadMenu.hpp"

using Standard::KeyValuePair;
using namespace Graphic::Menu;

namespace Management
{
    class MenuManager
    {
    private:
        ListTypeMenu* _listTypeMenu;
        MainMenu* _mainMenu;
        InsertMenu* _insertMenu;
        RemoveMenu* _removeMenu;
        SearchMenu* _searchMenu;
        SaveMenu* _saveMenu;
        LoadMenu* _loadMenu;

        string _listOption;
        string _mainMenuOption;
        string _insertMenuOption;
        string _removeMenuOption;
        string _loadMenuOption;
    public:
        MenuManager() {
            this->_listTypeMenu = nullptr;
            this->_mainMenu = nullptr;
            this->_insertMenu = nullptr;
            this->_removeMenu = nullptr;
            this->_searchMenu = nullptr;

            this->_listOption = "";
            this->_mainMenuOption = "";
            this->_insertMenuOption = "";
            this->_removeMenuOption = "";
        }
        ~MenuManager() {
            if (_listTypeMenu) delete _listTypeMenu;
            if (_mainMenu) delete _mainMenu;
            if (_insertMenu) delete _insertMenu;
            if (_removeMenu) delete _removeMenu;
            if (_searchMenu) delete _searchMenu;

            this->_listTypeMenu = nullptr;
            this->_mainMenu = nullptr;
            this->_insertMenu = nullptr;
            this->_removeMenu = nullptr;
            this->_searchMenu = nullptr;
        }

        std::string listen() {

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
