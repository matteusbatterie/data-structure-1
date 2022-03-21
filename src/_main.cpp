#include <iostream>
#include <sstream>
#include <string>
#include "./Classes/Sequential/List.hpp"
#include "./Classes/FileManaging/FileManager.hpp"
#include "./Constants/FilesNames.hpp"
#include "./Classes/Entities/Person.hpp"


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
    
    Sequential::List<Person> sequentialList = Sequential::List<Person>();

    FileManager fileManager;
    const string peopleStr = fileManager.read(fileName + "." + fileType);

    int i = 0;
    stringstream ssin(peopleStr);
    Person peopleArr[10];
    while (ssin.good() && i < 10) {
        string personName;
        string personIdStr;

        getline(ssin, personName, ',');
        getline(ssin, personIdStr);

        peopleArr[i] = Person(stoi(personIdStr.c_str()), personName);

        ++i;
    }

    for(const auto person : peopleArr)
    {
        sequentialList.append(person);
    }

    cout << sequentialList << endl;
}
