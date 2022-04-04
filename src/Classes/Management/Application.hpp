#pragma once
#include "../Management/ListManager.hpp"
#include "../Management/MenuManager.hpp"

namespace Management
{
    class Application
    {
    private:
        static Application* _instance;

        MenuManager* _menuManager;
        ListManager* _listManager;

    private:
        Application() {
            this->_menuManager = nullptr;
            this->_listManager = nullptr;
        }
        ~Application() {
            if (_menuManager) delete _menuManager;
            if (_listManager) delete _listManager;
            if (_instance) delete _instance;
        }
    public:
        Application(Application& other) = delete;
        static Application* instance() {
            if (_instance == nullptr) {
                _instance = new Application();
            }
            return _instance;
        }

        void operator=(const Application& other) = delete;


        void init() {
            _menuManager = new MenuManager();
            _listManager = new ListManager();

            std::cout << "1 - Sequential List\n";
            std::cout << "2 - Linked List\n";
            std::cout << ">> ";

            while (_menuManager->listOption() != "1"
                && _menuManager->listOption() != "2")
            {

                fflush(stdin);
                switch (getchar())
                {
                case '1':
                    _menuManager->listOption("1");
                    break;

                case '2':
                    _menuManager->listOption("2");
                    break;

                default:
                    std::cout << "Invalid option.\n";
                    break;
                }
            }

            mainMenu();
        }
        void mainMenu() {
            while (_menuManager->mainMenuOption() != "0")
            {
                std::cout << "1 - Insert\n";
                std::cout << "2 - Remove\n";
                std::cout << "3 - Search\n";
                std::cout << "4 - Display\n";
                std::cout << "5 - Save\n";
                std::cout << "6 - Load\n";
                std::cout << "0 - Quit\n";
                std::cout << ">> ";

                fflush(stdin);
                switch (getchar())
                {
                case '1':
                    _menuManager->mainMenuOption("1");
                    insertMenu();
                    break;
                case '2':
                    _menuManager->mainMenuOption("2");
                    removeMenu();
                    break;
                case '3':
                    _menuManager->mainMenuOption("3");
                    break;
                case '4':
                    _menuManager->mainMenuOption("4");
                    break;
                case '5':
                    _menuManager->mainMenuOption("5");
                    break;
                case '6':
                    _menuManager->mainMenuOption("6");
                    break;
                case '0':
                    _menuManager->mainMenuOption("0");
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    break;
                }
            }

            _menuManager->mainMenuOption("");
        }
        void insertMenu() {
            while (_menuManager->insertMenuOption() != "0")
            {
                std::cout << "1 - Insert at begin\n";
                std::cout << "2 - Insert at end\n";
                std::cout << "3 - Insert at position\n";
                std::cout << "0 - Quit\n";
                std::cout << ">> ";

                fflush(stdin);
                switch (getchar())
                {
                case '1':
                    _menuManager->insertMenuOption("1");
                    insertBegin();
                    break;
                case '2':
                    _menuManager->insertMenuOption("2");
                    insertEnd();
                    break;
                case '3':
                    _menuManager->insertMenuOption("3");
                    insertPosition();
                case '0':
                    _menuManager->insertMenuOption("0");
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    break;
                }
            }

            _menuManager->insertMenuOption("");
        }
        void removeMenu() {
            while (_menuManager->removeMenuOption() != "0")
            {
                std::cout << "1 - Remove from begin\n";
                std::cout << "2 - Remove from end\n";
                std::cout << "3 - Remove from position\n";
                std::cout << "0 - Quit\n";
                std::cout << ">> ";

                fflush(stdin);
                switch (getchar())
                {
                case '1':
                    _menuManager->removeMenuOption("1");
                    removeBegin();
                    break;
                case '2':
                    _menuManager->removeMenuOption("2");
                    removeEnd();
                    break;
                case '3':
                    _menuManager->removeMenuOption("3");
                    removePosition();
                case '0':
                    _menuManager->removeMenuOption("0");
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    break;
                }
            }
            _menuManager->removeMenuOption("");
        }

        void insertBegin() {
            string personName;
            int personId;

            std::cout << "Enter the person name:\n";
            std::cout << ">> ";
            cin >> personName;
            std::cout << "Enter the person ID:\n";
            std::cout << ">> ";
            cin >> personId;

            Person person = Person(personId, personName);

            if (_menuManager->listOption() == "1")
                _listManager->sequential()->insert(person, 0);

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->insert(person, 0);
        }
        void insertEnd() {
            string personName;
            int personId;

            std::cout << "Enter the person name:\n";
            std::cout << ">> ";
            cin >> personName;
            std::cout << "Enter the person ID:\n";
            std::cout << ">> ";
            cin >> personId;

            Person person = Person(personId, personName);

            if (_menuManager->listOption() == "1")
                _listManager->sequential()->append(person);

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->append(person);
        }
        void insertPosition() {
            int maxSize = 0;
            if (_menuManager->listOption() == "1")
                maxSize = _listManager->sequential()->size();
            else if (_menuManager->listOption() == "2")
                maxSize = _listManager->linked()->size();

            string personName;
            int personId;
            int position;

            std::cout << "Enter the person name:\n";
            std::cout << ">> ";
            cin >> personName;
            std::cout << "Enter the person ID:\n";
            std::cout << ">> ";
            cin >> personId;
            std::cout << "Enter the position (1 - " << maxSize + 1 << "):\n";
            std::cout << ">> ";
            cin >> position;

            Person person = Person(personId, personName);

            if (_menuManager->listOption() == "1" && position < maxSize)
                _listManager->sequential()->insert(person, position);
            else if (_menuManager->listOption() == "2" && position < maxSize)
                _listManager->linked()->insert(person, position);
        }

        void removeBegin() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->remove(0);

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->remove(0);
        }
        void removeEnd() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->pop();

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->pop();
        }
        void removePosition() {
            int maxSize = 0;
            if (_menuManager->listOption() == "1")
                maxSize = _listManager->sequential()->size() + 1;
            else if (_menuManager->listOption() == "2")
                maxSize = _listManager->linked()->size() + 1;

            string personName;
            int personId;
            int position;

            std::cout << "Enter the person name:\n";
            std::cout << ">> ";
            cin >> personName;
            std::cout << "Enter the person ID:\n";
            std::cout << ">> ";
            cin >> personId;
            std::cout << "Enter the position (1 - " << maxSize << "):\n";
            std::cout << ">> ";
            cin >> position;

            if (_menuManager->listOption() == "1")
                _listManager->sequential()->remove(position - 1);

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->remove(position - 1);
        }
    };

    Application* Application::_instance = nullptr;
}
