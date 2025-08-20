#include <iostream>
#include <string>
#include <cstdlib>
#include "applications.hpp"

using namespace std;

void fileManager() {
    system("cls");
    cout << "DoorsOS File Manager" << endl;

    string *file1 = new string("File1.txt");
    cout << *file1 << endl;
}