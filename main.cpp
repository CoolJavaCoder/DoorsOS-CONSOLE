#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>


using namespace std;
void doorpax();
void fileManager();
void Terminal();
string apps[7] = {"File Manager", "Terminal", "Text Editor"};


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
        cout << " - " << apps[0] << endl;
        cout << " - " << apps[1] << endl;
        cout << " - " << apps[2] << endl;
        cout << " - " << apps[3] << endl;
        cout << " - " << apps[4] << endl;
        cout << " - " << apps[5] << endl;
        cout << " - " << apps[6] << endl;
        cout << "What app would you like to use?: " << endl;
        string appChoice;
        getline(cin, appChoice);
        cout << "You have chosen: " << appChoice << endl;
        if (appChoice == "File Manager") {
            fileManager();
        }
        else if (appChoice == "Terminal") {
            Terminal();
        } else if (appChoice == "Text Editor") {
            cout << "DOORS TEXT EDITOR" << endl;
            string fileToEdit;
            cout << "Enter the name of the file to edit: ";
            getline(cin, fileToEdit);
            ofstream file(fileToEdit, ios::in | ios::out | ios::app);
            if (file.is_open()) {
                cout << "Editing file: " << fileToEdit << endl;
                cout << "Enter text to append to the file (type 'exit' on a new line to finish):" << endl;
                string line;
                while (true) {
                    getline(cin, line);
                    if (line == "exit") {
                        break;
                    }
                    file << line << endl;
                }
                file.close();
                cout << "File saved." << endl;
            } else {
                cout << "Unable to open file." << endl;
            }
        } else if (appChoice == "Guessing Game"){
            cout << "Welcome to the Guessing Game!" << endl;
            int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
            int userGuess;
            do {
                cout << "Enter your guess (1-100): ";
                cin >> userGuess;
                if (userGuess < numberToGuess) {
                    cout << "Too low! Try again." << endl;
                } else if (userGuess > numberToGuess) {
                    cout << "Too high! Try again." << endl;
                }
            } while (userGuess != numberToGuess);
            cout << "Congratulations! You guessed the number." << endl;
        } else if (appChoice == "TaskTamer") {
            string tasks[10];
            cout << "Welcome to TaskTamer!" << endl;
            cout << "Enter a task to set as todo: ";
            string todoTask;
            getline(cin, todoTask);
            cout << "Task added to your todo list: " << todoTask << endl;
            for (int i = 0; i < 10; i++) {
                if (tasks[i].empty()) {
                    tasks[i] = todoTask;
                    ofstream taskFile("tasks.txt", ios::app);
                    if (taskFile.is_open()) {
                        taskFile << todoTask << endl;
                        taskFile.close();
                    } else {
                        cout << "Unable to open file to save tasks." << endl;
                    }
                    break;
                }
            }
        } else if(appChoice == "System Commander") {
            cout << "Welcome to System Commander" << endl;
            cout << "You can execute your host operating system commands here." << endl;
            string command;
            while (true != false) {
                cout << "Enter a command: ";
                getline(cin, command);
                system(command.c_str());
                if (command == "exit") {
                    break;
                }
            }
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
    string newFileName;
    string fileAction;
    string files[10] = {};
    
    while (true) {
        cout << "Enter an action to do with your files (new, list, exit)" << endl;
        getline(cin, fileAction);
        if(fileAction == "new"){
               cout << "Enter the name for the new file: ";
               getline(cin, newFileName);
               for (int i = 0; i < 10; i++) {
                   if (files[i].empty()) {
                       files[i] = newFileName;
                       cout << "File created: " << newFileName << endl;
                       ofstream newFile(newFileName);
                       if (newFile.is_open()) {
                           newFile << ""; // Create an empty file
                           newFile.close();
                       } else {
                           cout << "Unable to create file." << endl;
                       }
                       break;
                   }
               }
        } else if(fileAction == "list"){
            cout << "Listing files:" << endl;
            for(int i = 0; i < 10; i++) {
                if (!files[i].empty()) {
                    cout << " - " << files[i] << endl;
                } else {
                    cout << " - " << endl;
                }
            }
            
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

void doorpax(){
    cout << "DOORS PACKAGE MANAGER" << endl;
    while(true) {
        cout << "DoorPax> ";
        string package;
        getline(cin, package);
        if (package == "exit") {
            cout << "Exiting DoorPax." << endl;
            break;
        } else if(package == "guessnumber"){
            string GuessingGame = "Guessing Game";
            cout << "Getting packages..." << endl;
            sleep(3);
            cout << "Packages retrieved successfully." << endl;
            for(int i = 0; i < 7; i++) {
                if (apps[i] == GuessingGame) {
                    cout << "Guessing Game is already installed." << endl;
                    return;
                }
                else if(apps[i].empty()) {
                    apps[i] = GuessingGame;
                    cout << "Guessing Game installed successfully." << endl;
                    return;
                }
            }
        } else if(package == "todo"){
            string TodoApp = "TaskTamer";
            cout << "Getting packages..." << endl;
            sleep(3);
            cout << "Packages retrieved successfully." << endl;
            for(int i = 0; i < 7; i++) {
                if (apps[i] == TodoApp) {
                    cout << "TaskTamer is already installed." << endl;
                    return;
                }
                else if(apps[i].empty()) {
                    apps[i] = TodoApp;
                    cout << "TaskTamer installed successfully." << endl;
                    return;
                }
            }
        } else if(package == "help") {
            cout << "Available packages: guessnumber, todo" << endl;
            cout << "Type the package name to install it." << endl;
            cout << "Type 'exit' to exit DoorPax." << endl;
        } else if(package == "syscmd"){
            string sysCmds = "System Commander";
            cout << "Getting packages..." << endl;
            sleep(3);
            cout << "Packages retrieved successfully." << endl;
            for(int i = 0; i < 7; i++) {
                if (apps[i] == sysCmds) {
                    cout << "System Commander is already installed." << endl;
                    return;
                }
                else if(apps[i].empty()) {
                    apps[i] = sysCmds;
                    cout << "System Commander installed successfully." << endl;
                    return;
                }
            }
        } else {
            cout << "Unknown package command: " << package << endl;
        }
    }
}

void Terminal(){
    cout << "DOORS TERMINAL" << endl;
    while(true) {
        cout << "Terminal> ";
        string command;
        getline(cin, command);
        if (command == "exit") {
            cout << "Exiting terminal." << endl;
            break;
        } else if (command == "help") {
            cout << "Available commands: help, exit, echo, explain, lsapps, start" << endl;
        } else if (command.rfind("echo ", 0) == 0) {
            echo(command.substr(5));
        } else if (command.rfind("explain", 0) == 0) {
            cout << "The DOORS operating system is a simple, user-friendly OS designed for ease of use." << endl;
            cout << "After all, why open a Window when you can just use a Door?" << endl;
            cout << "This terminal does not do much right now, more coming soon!" << endl;
        } else if (command.rfind("lsapps", 0) == 0) {
            cout << "Listing applications:" << endl;
            cout << " - " << apps[0] << endl;
            cout << " - " << apps[1] << endl;
            cout << " - " << apps[2] << endl;
            cout << " - " << apps[3] << endl;
            cout << " - " << apps[4] << endl;
            cout << " - " << apps[5] << endl;
            cout << " - " << apps[6] << endl;
        } else if (command.rfind("start", 0) == 0) {
            cout << "Starting application: " << command.substr(6) << endl;
            if (command.substr(6) == "File Manager") {
                fileManager();
            } else if (command.substr(6) == "Terminal") {
                Terminal();
            } else if (command.substr(6) == "DoorPax") {    
                cout << "This is the DoorsOS exclusive package manager";
                doorpax();
            } else {
                cout << "Unknown application: " << command.substr(6) << endl;
            }
        } else if (command.rfind("DoorPax", 0) == 0) {
            doorpax();
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }
}