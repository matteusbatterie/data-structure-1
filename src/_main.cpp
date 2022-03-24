#include <iostream>
#include <sstream>
#include <string>
#include "./Classes/FileManaging/FileManager.hpp"
#include "./Classes/Sequential/List.hpp"
#include "./Classes/Entities/Person.hpp"
#include "./Constants/FilesNames.hpp"

using namespace std;
using namespace DataStructure::Query;
using namespace Constants::PeopleFilesNames;
using namespace FileConfiguration;
using namespace Entities;

void firstPresentation();
void terminateApplication();

int main()
{
    firstPresentation();

    terminateApplication();
    return 0;
}

void terminateApplication()
{
    cout << endl << endl << endl << "Application terminated." << endl << endl << endl;
    getchar();
}

void firstPresentation()
{
    auto [fileName, fileType] = NAME_AND_ID_10;
    Sequential::List<Person> sequentialList = FileManager().readAsListSequential(fileName + "." + fileType);

    cout << sequentialList << endl;
}
