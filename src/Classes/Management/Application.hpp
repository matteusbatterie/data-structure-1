#pragma once
#include "./File/FileManager.hpp"
#include "../Management/ListManager.hpp"
#include "../Management/MenuManager.hpp"
#include "../Constants/FilesNames.hpp"


namespace Management
{
    using namespace File;

    class Application
    {
    private:
        static Application* _instance;

        MenuManager* _menuManager;
        ListManager* _listManager;
        FileManager* _fileManager;

    private:
        Application() {
            this->_menuManager = nullptr;
            this->_listManager = nullptr;
            this->_fileManager = nullptr;
        }
        ~Application() {
            if (_menuManager) delete _menuManager;
            if (_listManager) delete _listManager;
            if (_fileManager) delete _fileManager;
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


            while (_menuManager->listOption() != "1"
                && _menuManager->listOption() != "2")
            {
                std::cout << "1 - Sequential List\n";
                std::cout << "2 - Linked List\n";
                std::cout << ">> ";

                char option = getchar();
                clearBuffer();
                switch (option)
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
                std::cout << "3 - Sort\n";
                std::cout << "4 - Search\n";
                std::cout << "5 - Display\n";
                std::cout << "6 - Save\n";
                std::cout << "7 - Load\n";
                std::cout << "0 - Quit\n";
                std::cout << ">> ";

                char option = getchar();
                clearBuffer();
                switch (option)
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
                    sortMenu();
                    break;
                case '4':
                    _menuManager->mainMenuOption("4");
                    search();
                    break;
                case '5':
                    _menuManager->mainMenuOption("5");
                    display();
                    break;
                case '6':
                    _menuManager->mainMenuOption("6");
                    save();
                    break;
                case '7':
                    _menuManager->mainMenuOption("7");
                    load();
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

                char option = getchar();
                switch (option)
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

                char option = getchar();
                clearBuffer();
                switch (option)
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
            clearBuffer();
            cin >> personName;

            std::cout << "Enter the person ID:\n";
            std::cout << ">> ";
            clearBuffer();
            cin >> personId;

            std::cout << "Enter the position (1 - " << maxSize << "):\n";
            std::cout << ">> ";
            clearBuffer();
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

            int position;
            std::cout << "Enter the position (1 - " << maxSize << "):\n";
            std::cout << ">> ";
            cin >> position;

            if (_menuManager->listOption() == "1")
                _listManager->sequential()->remove(position - 1);

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->remove(position - 1);
        }

        void sortMenu() {
            while (_menuManager->sortMenuOption() != "0")
            {
                std::cout << "1 - Selection Sort\n";
                std::cout << "2 - Insertion Sort\n";
                std::cout << "3 - Bubble Sort\n";
                std::cout << "4 - Shell Sort\n";
                std::cout << "5 - Quick Sort\n";
                std::cout << "6 - Merge Sort\n";
                std::cout << "0 - Quit\n";

                char option = getchar();
                clearBuffer();
                switch (option)
                {
                case '1':
                    _menuManager->sortMenuOption("1");
                    selectionSort();
                    break;
                case '2':
                    _menuManager->sortMenuOption("2");
                    insertionSort();
                    break;
                case '3':
                    _menuManager->sortMenuOption("3");
                    bubbleSort();
                    break;
                case '4':
                    _menuManager->sortMenuOption("4");
                    shellSort();
                    break;
                case '5':
                    _menuManager->sortMenuOption("5");
                    quickSort();
                    break;
                case '6':
                    _menuManager->sortMenuOption("6");
                    mergeSort();
                    break;
                case '0':
                    _menuManager->sortMenuOption("0");
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    break;
                }
            }
            _menuManager->sortMenuOption("");
        }

        void selectionSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->selectionSort();
            // else if (_menuManager->listOption() == "2")
            //     _listManager->linked()->selectionSort();
        }
        void insertionSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->insertionSort();
            // else if (_menuManager->listOption() == "2")
            //     _listManager->linked()->insertionSort();
        }
        void bubbleSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->bubbleSort();
            // else if(_menuManager->listOption() == "2")
            //     _listManager->linked()->bubbleSort();
        }
        void shellSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->shellSort();
            // else if(_menuManager->listOption() == "2")
                //_listManager->linked()->shellSort();
        }
        void quickSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->quickSort();
            // else if(_menuManager->listOption() == "2")
                //_listManager->linked()->quickSort();
        }
        void mergeSort() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->mergeSort();
            // else if(_menuManager->listOption() == "2")
                //_listManager->linked()->mergeSort();
        }

        void search() {
            int personId;

            std::cout << "Enter the person's ID:\n";
            std::cout << ">> ";
            std::cin >> personId;

            Person result;

            if (_menuManager->listOption() == "1")
                result = _listManager->sequential()->find(Person(personId));

            else if (_menuManager->listOption() == "2")
                result = _listManager->linked()->find(Person(personId));

            if (result.id() != 0)
                std::cout << result << '\n';
        }

        void display() {
            if (_menuManager->listOption() == "1")
                _listManager->sequential()->print();

            else if (_menuManager->listOption() == "2")
                _listManager->linked()->print();
        }

        void save() {
            string fileName;
            std::cout << "Enter the file name:\n";
            std::cout << ">> ";
            std::cin >> fileName;

            if (_menuManager->listOption() == "1")
                _fileManager->write(fileName, *(_listManager->sequential()));
            else if (_menuManager->listOption() == "2")
                for (Person& person : *_listManager->linked())
                {
                    string line = person.id() + ", " + person.name();
                    _fileManager->write(fileName, line);
                }
        }
        void load() {
            using namespace Constants::PeopleFilesNames;

            _fileManager = new FileManager();
            string loadedFile = "";
            while (loadedFile == "")
            {
                std::cout << "Pick a preset file:\n";
                std::cout << "1 - " << NAME_AND_ID_10.name << '\n';
                std::cout << "2 - " << NAME_AND_ID_50.name << '\n';
                std::cout << "3 - " << NAME_AND_ID_100.name << '\n';
                std::cout << "4 - " << NAME_AND_ID_1K.name << '\n';
                std::cout << "5 - " << NAME_AND_ID_10K.name << '\n';
                std::cout << "6 - " << NAME_AND_ID_1M.name << '\n';
                std::cout << "7 - " << NAME_AND_ID_100M.name << '\n';
                std::cout << "0 - Quit\n";
                std::cout << ">> ";

                char option = getchar();
                clearBuffer();
                switch (option)
                {
                case '1':
                    loadedFile = NAME_AND_ID_10.name + "." + NAME_AND_ID_10.type;
                    break;
                case '2':
                    loadedFile = NAME_AND_ID_50.name + "." + NAME_AND_ID_50.type;
                    break;
                case '3':
                    loadedFile = NAME_AND_ID_100.name + "." + NAME_AND_ID_100.type;
                    break;
                case '4':
                    loadedFile = NAME_AND_ID_1K.name + "." + NAME_AND_ID_1K.type;
                    break;
                case '5':
                    loadedFile = NAME_AND_ID_10K.name + "." + NAME_AND_ID_10K.type;
                    break;
                case '6':
                    loadedFile = NAME_AND_ID_1M.name + "." + NAME_AND_ID_1M.type;
                    break;
                case '7':
                    loadedFile = NAME_AND_ID_100M.name + "." + NAME_AND_ID_100M.type;
                    break;
                case '0':
                    loadedFile = NAME_AND_ID_10.name + "." + NAME_AND_ID_10.type;
                    break;
                default:
                    std::cout << "Invalid option.\n";
                    break;
                }

                if (_menuManager->listOption() == "1")
                    _listManager->sequential(_fileManager->readAsListSequential(loadedFile));
                else if (_menuManager->listOption() == "2")
                    _listManager->linked(_fileManager->readAsListLinked(loadedFile));
            }


        }

        void clearBuffer();
    };

    Application* Application::_instance = nullptr;

    void Application::clearBuffer()
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}
