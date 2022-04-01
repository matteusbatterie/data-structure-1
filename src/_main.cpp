#include <iostream>
#include <sstream>
#include <string>
#include "./Classes/FileManaging/FileManager.hpp"
#include "./Classes/Sequential/List.hpp"
#include "./Classes/Entities/Person.hpp"
#include "./Constants/FilesNames.hpp"
#include "./Classes/Standard/Array.hpp"
#include "./Classes/Graphic/Menu/MainMenu.hpp"

using std::cout;
using namespace DataStructure::Query;
using namespace Constants;
using namespace FileConfiguration;
using namespace Entities;
using namespace Standard;
using namespace Graphic::Menu;

void firstPresentation();
void secondPresentation();

void terminateApplication();
void pause();

int main()
{
    MainMenu menu = MainMenu();
    menu.init();

    terminateApplication();
    return 0;
}

void firstPresentation()
{
    auto [fileName, fileType] = PeopleFilesNames::NAME_AND_ID_10;
    Sequential::List<Person> sequentialList = FileManager().readAsListSequential(fileName + "." + fileType);

    cout << sequentialList << '\n';
}
void secondPresentation()
{
    auto [fileName, fileType] = PeopleFilesNames::NAME_AND_ID_10;
    Linked::List<Person> linkedList = FileManager().readAsListLinked(fileName + "." + fileType);

    cout << linkedList << '\n';
}

void terminateApplication()
{
    cout << "\n\n" << "Application terminated.\n";
    pause();
}

void pause()
{
    cout << "Press any key to continue...\n";
    getchar();
}
