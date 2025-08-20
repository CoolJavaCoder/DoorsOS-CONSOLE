#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int performAction(string action) {
    if (action == "help") {
        cout << "Welcome to the Doors Operating System. Here are some commands you can use:" << endl;
        cout << " - help: Show this help message" << endl;
        cout << " - exit: Exit the program" << endl;
        cout << " - version: Show the version information" << endl;
    } else if (action == "exit") {
        cout << "Goodbye!" << endl;
        exit(0);
    } else if (action == "version") {
        cout << "DoorsOS Version 1.0.0" << endl;
    } else if (action == "app library"){
        cout << "Available applications:" << endl;
        cout << " - Text Editor" << endl;
        cout << " - File Manager" << endl;
        cout << " - Terminal" << endl;
    }
    return 0;
}

int main() {
    cout << "/$$$$$$$$ /$$                       /$$$$$$$                                                 /$$$$$$   /$$$$$$ " << endl;
    cout << "|__  $$__/| $$                      | $$__  $$                                               /$$__  $$ /$$__  $$" << endl;
    cout << "   | $$   | $$$$$$$   /$$$$$$       | $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$      | $$  \\ $$| $$  \\__/" << endl;
    cout << "   | $$   | $$__  $$ /$$__  $$      | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$_____/      | $$  | $$|  $$$$$$ " << endl;
    cout << "   | $$   | $$  \\ $$| $$$$$$$$      | $$  | $$| $$  \\ $$| $$  \\ $$| $$  \\__/|  $$$$$$       | $$  | $$ \\____  $$" << endl;
    cout << "   | $$   | $$  | $$| $$_____/      | $$  | $$| $$  | $$| $$  | $$| $$       \\____  $$      | $$  | $$ /$$  \\ $$" << endl;
    cout << "   | $$   | $$  | $$|  $$$$$$$      | $$$$$$$/|  $$$$$$/|  $$$$$$/| $$       /$$$$$$$/      |  $$$$$$/|  $$$$$$/" << endl;
    cout << "   |__/   |__/  |__/ \\_______/      |_______/  \\______/  \\______/ |__/      |_______/        \\______/  \\______/ " << endl;
    
    string actionPreformed;
    string *actionPreformedptr;

    while (true != false)  // Infinite loop to keep asking for input
    {
        cout << "What would you like to do?: ";
        getline(cin, actionPreformed);
        actionPreformedptr = &actionPreformed;
        performAction(*actionPreformedptr);
    }
    
    //cout << "What would you like to do?: ";
    //getline(cin, actionPreformed);
    //actionPreformedptr = &actionPreformed;
    //performAction(*actionPreformedptr);

    return 0;

}
