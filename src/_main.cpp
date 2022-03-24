#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include "./Classes/FileManaging/FileManager.hpp"
#include "./Classes/Sequential/List.hpp"
#include "./Classes/Entities/Person.hpp"
#include "./Constants/FilesNames.hpp"

using std::cout;
using namespace DataStructure::Query;
using namespace Constants::PeopleFilesNames;
using namespace FileConfiguration;
using namespace Entities;

void firstPresentation();
void terminateApplication();
void pause();

int main()
{
    firstPresentation();

    terminateApplication();
    return 0;
}

void firstPresentation()
{
    auto [fileName, fileType] = NAME_AND_ID_10;
    Sequential::List<Person> sequentialList = FileManager().readAsListSequential(fileName + "." + fileType);

    cout << sequentialList << "\n";
}

void terminateApplication()
{
    cout << "\n\n\n" << "Application terminated.\n";
    pause();
}

void pause()
{
    cout << "Press any key to continue...\n";
    while (!kbhit()) {}
}
