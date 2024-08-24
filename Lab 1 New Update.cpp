#include <iostream>
#include <string>
#include <direct.h>
#include <windows.h>

using namespace std;

void ListFiles(String DirectPath, String Filter = "" ){
	FindData FindFileData;
	HandleFind = FirstFile((DirectPath + "\\*").c_str(), FindFileData);
	
	if  (HandleFind == InvalidHandleVal){
		cout << "Cannot access directory: " << DirectPath << endl;
		return;
	}
	
	do {
        string FileName = FindFileData.cFileName;
        if (filter.empty() || FileName.find(filter) != string::npos) {
            cout << FileName << endl;
        }
    } while (NextFile(HandleFind, FindFileData) != 0);

    FindClose(HandleFind);
}

void CreateDirectory(String DirectName) {
    if (MakeDirect(DirectName.c_str()) == 0) {
        cout << "New Directory created successfully." << endl;
    } else {
        cout << "Failed to new create directory. It may already exist or there was an error." << endl;
    }
}

void ChangeDirectory(const string& path) {
    if (ChanDirect(path.c_str()) == 0) {
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        cout << "Current directory changed to: " << cwd << endl;
    } else {
        cout << "Error changing directory to: " << path << endl;
    }
}

void MainMenu(){
	cout << "---------" << endl;
	cout << "Main Menu" << endl;
	cout << "---------" << endl;
	cout << "[1]-List of Files" << endl;
	cout << "[2]-Create a New Directory" << endl;
	cout << "[3]-Change the Working Directory" << endl;
	cout << "[4]-Exit" << endl; //to terminate the program
	cout << "Enter the number you have chosen: ";
}

void ListFiles() {
    cout << "List Files" << endl;
         << "[1] - All Files" << endl;
         << "[2] - Extension Files" << endl;
         << "[3] - Name Wise" << endl;
         << "[4] - Back to Main Menu" << endl;
         << "Select and Enter the number you have chosen: ";
         
}
int main() {
	int choice;
	String DirectName, filter;
	
	while (true) {
		MainMenu();
		cin >> choice;
		
		if (choice == 1) {
			ListFiles();
			int Options;
			cin >> Options;
			
			if (Options == 1) {
				ListFiles(".");
			} else if (Options == 2) {
				cout << "Enter the Extension File: " << endl;
				cin >> filter;
				ListFiles(".", filter);
			} else if (Options == 3) {
				cout << "Enter the Name Wise: " << endl;
				cin >> filter;
				ListFiles(".", filter);
			} else if (Options == 4){
				continue;
			} else {
				cout << "Invalic choice. Please try again and refer to the choices given. : )" << endl;
			}
		} else if (choice == 2) {
			cout << "Enter the name of the new directory: ";
			cin >> DirectName;
			CreateDirectory(DirectName);
		} else if (choice == 3){
			cout << "Change Directory" << endl;
			cout << "[1] - Step by Step Backward" << endl;
			cout << "[2] - Goto Root Directory" << endl;
			cout << "[3] - Forward Directory" << endl;
			cout << "[4] - Back to Main Menu" << endl;
			cout << "Enter the number you have chosen: " << endl;
			int cDirectChoice;
			cin >> cDirectChoice;
 		} 
	}
}








