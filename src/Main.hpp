#pragma once
#include <iostream>
#include "./Classes/Management/File/FileManager.hpp"
#include "./Classes/Constants/FilesNames.hpp"
#include "./Classes/Management/Application.hpp"

using namespace Management::File;
using namespace Constants;
using namespace Management;

// Represents an object for the main class of the application.
class Main
{
private:
    static Main* _instance;
    Application* _application;

private:
    Main() {
        this->_application = Application::instance();
    }
    ~Main() {
        if (_instance) delete _instance;
    }

public:
    Main(Main& other) = delete;
    static Main* instance() {
        if (_instance == nullptr) {
            _instance = new Main();
        }
        return _instance;
    }

    void operator=(const Main& other) = delete;

    void run() {
        _application->init();
        terminate();
    }

    void terminate() {
        std::cout << "\n\n" << "Application terminated.\n";
        pause();
    }
    void pause() {
        std::cout << "Press any key to continue...\n";
        fflush(stdin);
        getchar();
    }

    void firstPresentation();
    void secondPresentation();
};

Main* Main::_instance = nullptr;

void Main::firstPresentation() {
    auto [fileName, fileType] = PeopleFilesNames::NAME_AND_ID_10;
    Sequential::List<Person> sequentialList = FileManager().readAsListSequential(fileName + "." + fileType);

    cout << sequentialList << '\n';
}
void Main::secondPresentation() {
    auto [fileName, fileType] = PeopleFilesNames::NAME_AND_ID_10;
    Linked::List<Person> linkedList = FileManager().readAsListLinked(fileName + "." + fileType);

    cout << linkedList << '\n';
}

