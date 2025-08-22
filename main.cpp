#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
void fileManager();
void terminal();

int performAction(string action) {
    if (action == "help") {
        cout << "Welcome to the Doors Operating System. Here are some commands you can use:" << endl;
        cout << " - help: Show this help message" << endl;
        cout << " - exit: Exit the OS" << endl;
        cout << " - version: Show the version information" << endl;
        cout << " - app library: Show the available applications and use them." << endl;
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
        cout << "What app would you like to use?: " << endl;
        string appChoice;
        getline(cin, appChoice);
        cout << "You have chosen: " << appChoice << endl;
        if (appChoice == "File Manager") {
            fileManager();
        }
        else if (appChoice == "Terminal") {
            terminal();
        } else if (appChoice == "Text Editor") {
            cout << "Text Editor is not implemented yet." << endl;
        } else {
            cout << "Unknown application: " << appChoice << endl;
        }
    } else {
        cout << "Unknown command: " << action << endl;
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
void fileManager() {
    cout << "DOORS FILES" << endl;
    cout << "You can store up to ten files here." << endl;
    string fileAction;
    string files[10];
    string file1;
    string file2;
    string file3;
    string file4;
    files[0] = file1;
    files[1] = file2;
    files[2] = file3;
    files[3] = file4;

    while (true) {
        cout << "Enter an action to do with your files (new, edit, delete, list, exit)" << endl;
        getline(cin, fileAction);
        if(fileAction == "new"){
               cout << "Enter the name for the new file: ";
               string newFileName;
               getline(cin, newFileName);
               for (int i = 0; i < 6; i++) {
                   if (files[i].empty()) {
                       files[i] = newFileName;
                       cout << "File created: " << newFileName << endl;
                       break;
                   }
               }
        } else if(fileAction == "list"){
            cout << "Listing files:" << endl;
            cout << " - " << files[0] << endl;
            cout << " - " << files[1] << endl;
            cout << " - " << files[2] << endl;
            cout << " - " << files[3] << endl;
            cout << " - " << files[4] << endl;
            cout << " - " << files[5] << endl;
            cout << " - " << files[6] << endl;
            cout << " - " << files[7] << endl;
            cout << " - " << files[8] << endl;
            cout << " - " << files[9] << endl;
        } else if(fileAction == "delete"){
            cout << "Enter the name of the file you want to delete: ";
            string deleteFileName;
            getline(cin, deleteFileName);
            for (int i = 0; i < 10; i++) {
                if (files[i] == deleteFileName) {
                    files[i].clear();
                    cout << "File deleted: " << deleteFileName << endl;
                    break;
                }
            }
        } else if(fileAction == "exit"){
            cout << "Exiting file manager." << endl;
            break;
        }
    }
    
} 
void echo(string message){
    cout << message << endl;
}   
void terminal() {
    cout << "DOORS TERMINAL" << endl;
    while(true) {
        cout << "Terminal> ";
        string command;
        getline(cin, command);
        if (command == "exit") {
            cout << "Exiting terminal." << endl;
            break;
        } else if (command == "help") {
            cout << "Available commands: help, exit, echo, explain, lsapps" << endl;
        } else if (command.rfind("echo ", 0) == 0) {
            echo(command.substr(5));
        } else if (command.rfind("explain", 0) == 0) {
            cout << "The DOORS operating system is a simple, user-friendly OS designed for ease of use." << endl;
            cout << "After all, why open a Window when you can just use a Door?" << endl;
            cout << "This terminal does not do much right now, more coming soon!" << endl;
        } else if (command.rfind("lsapps", 0) == 0) {
            cout << "Listing applications:" << endl;
            cout << " - File Manager" << endl;
            cout << " - Terminal" << endl;
            cout << " - Text Editor (not implemented)" << endl;
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }
}