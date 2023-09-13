#pragma once
#include <iostream>
#include "./Classes/Management/File/FileManager.hpp"
#include "./Constants/FilesNames.hpp"
#include "./Classes/Management/Application.hpp"

using namespace Management::File;
using namespace Constants;
using namespace Management;

namespace Program
{
    /**
     * Singleton that represents the main class of the program, can be initialized using the static method "instance()"
    */
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
        
        /**
         * Starts the application
        */
        void run() {
            _application->run();
        }
    };

    Main* Main::_instance = nullptr;
};