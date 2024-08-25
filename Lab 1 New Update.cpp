#include <iostream>
#include <string> // allow to work with strings
#include <direct.h> // for the use of _mkdir and _chdir
#include <windows.h> // for the use of FindFirstFile and FindNextFile

using namespace std;

void ListFiles(const string& DirectPath, const string& Filter = "") { // method where you can list the files
    WIN32_FIND_DATA FindFileData;
    HANDLE HandleFind = FindFirstFile((DirectPath + "\\*").c_str(), &FindFileData);

    if (HandleFind == INVALID_HANDLE_VALUE) {
        cout << "Cannot access directory: " << DirectPath << endl;
        return;
    }

    do {
        string FileName = FindFileData.cFileName;
        if (Filter.empty() || FileName.find(Filter) != string::npos) {
            cout << FileName << endl;
        }
    } while (FindNextFile(HandleFind, &FindFileData) != 0);

    FindClose(HandleFind);
}

void CreateDirectory(const string& DirectName) { // method where you can create a new directory
    if (_mkdir(DirectName.c_str()) == 0) {
        cout << "New Directory created successfully." << endl;
    } else {
        cout << "Failed to create new directory. It may already exist or there was an error." << endl;
    }
}

void ChangeDirectory(const string& path) { // method where you can change a directory into another directory
    if (_chdir(path.c_str()) == 0) {
        char cwd[256];
        _getcwd(cwd, sizeof(cwd));
        cout << "Current directory changed to: " << cwd << endl;
    } else {
        cout << "Error changing directory to: " << path << endl;
    }
}

void ShowCurrentDirectory() { // method where you can show the current directory you are using
    char cwd[256];
    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        cout << "Current Directory: " << cwd << endl;
    } else {
        cout << "Error getting current directory." << endl;
    }
}

void MainMenu() { // method to display the Main Menu
    cout << " " << endl;
    cout << "---------" << endl;
    cout << "Main Menu" << endl;
    cout << "---------" << endl;
    cout << "[1] - List of Files" << endl;
    cout << "[2] - Create a New Directory" << endl;
    cout << "[3] - Change the Working Directory" << endl;
    cout << "[4] - Show Current Directory" << endl;
    cout << "[5] - Exit" << endl;
    cout << "Enter the number you have chosen: ";
}

void ListFilesMenu() { // method to display all the files, extension files, or by the use of Name Wise
    cout << " " << endl;
    cout << "List Files" << endl;
    cout << "[1] - All Files" << endl;
    cout << "[2] - Extension Files" << endl;
    cout << "[3] - Name Wise" << endl;
    cout << "[4] - Back to Main Menu" << endl;
    cout << "Select and Enter the number you have chosen: ";
}

int main() {
    int choice;
    string DirectName, filter;

    while (true) {
        MainMenu();
        cin >> choice;

        if (choice == 1) {
            ListFilesMenu();
            int Options;
            cin >> Options;

            if (Options == 1) {
                ListFiles(".");
            } else if (Options == 2) {
                cout << "Enter the Extension File: ";
                cin >> filter;
                ListFiles(".", filter);
                cout << "Files with extension " << filter << " listed successfully." << endl;
            } else if (Options == 3) {
                cout << "Enter the Name: ";
                cin >> filter;
                ListFiles(".", filter);
            } else if (Options == 4) {
                continue;
            } else {
                cout << "Invalid choice. Please try again and refer to the choices given. :)" << endl;
            }
        } else if (choice == 2) {
            cout << "Enter the name of the new directory(example: NewFolder): ";
            cin >> DirectName;
            CreateDirectory(DirectName);
        } else if (choice == 3) {
            cout << " " << endl;
            cout << "Change Directory" << endl;
            cout << "[1] - Step by Step Backward" << endl;
            cout << "[2] - Go to Root Directory" << endl;
            cout << "[3] - Forward Directory" << endl;
            cout << "[4] - Back to Main Menu" << endl;
            cout << "Enter the number you have chosen: ";
            int cDChoice;
            cin >> cDChoice;

            if (cDChoice == 1) {
                ChangeDirectory("..");
            } else if (cDChoice == 2) {
                ChangeDirectory("C:\\");
            } else if (cDChoice == 3) {
                cout << "Enter the path of the directory(example: NewFolder, Documents): ";
                cin >> DirectName;
                ChangeDirectory(DirectName);
            } else if (cDChoice == 4) {
                continue;
            } else {
                cout << "Invalid choice. Please try again and refer to the choices given. :)" << endl;
            }
        } else if (choice == 4) {
        	cout << " " << endl;
            ShowCurrentDirectory();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again and refer to the choices given. :)" << endl;
        }
    }

    return 0;
}
