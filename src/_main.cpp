#include <iostream>
#include <sstream>
#include "./Classes/Sequential/List.hpp"
#include "./Classes/FileManaging/FileManager.hpp"
#include "./Constants/FilesNames.hpp"


using std::cout;
using std::endl;
using std::stringstream;
using namespace DataStructure::Query;
using namespace Constants::PeopleFilesNames;
using namespace FileConfiguration;

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
    system("pause");
}

void firstPresentation()
{
    // const auto [fileName, fileType] = NAME_AND_ID_10;
    const string fileName = NAME_AND_ID_10.name;
    const string fileType = NAME_AND_ID_10.type;
    Sequential::List<string> sequentialList = Sequential::List<string>();

    FileManager fileManager;
    const string peopleStr = fileManager.read(fileName + "." + fileType);

    int i = 0;
    stringstream ssin(peopleStr);
    string peopleArr[10];
    while (ssin.good() && i < 10) {
        ssin >> peopleArr[i];
        ++i;
    }

    for(const auto person : peopleArr)
    {
        sequentialList.append(person);
    }


    cout << sequentialList << endl;
}
