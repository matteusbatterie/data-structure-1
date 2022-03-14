#include <iostream>
#include "./Sequential/List.hpp"

using std::cout;
using std::endl;
using namespace DataStructure::Query::Sequential;

void terminateApplication();

int main()
{
    List<int> sequentialList = List<int>();
    cout << sequentialList << endl;

    sequentialList.append(1);
    cout << sequentialList << endl;

    sequentialList.append(10);
    cout << sequentialList << endl;

    terminateApplication();
    return 0;
}


void terminateApplication()
{
    cout << endl << endl<< endl << "Application terminated." << endl << endl << endl;
}
