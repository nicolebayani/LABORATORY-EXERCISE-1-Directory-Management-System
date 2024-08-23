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






















int main()
{
	int choice;
	cout << "---------" << endl;
	cout << "Main Menu" << endl;
	cout << "---------" << endl;
	
	do{
	
		cout << "[1]-List of Files" << endl;
		cout << "[2]-Create a New Directory" << endl;
		cout << "[3]-Change the Working Directory" << endl;
		cout << "[4]-Exit" << endl; //to terminate the program
		cout << "Enter the number you have chosen: ";
		cin >> choice; // so you can choose in the main menu
		
		switch (choice){
			case 1: cout << "[1]All Files" << endl;
					cout << "[2]Extension Files" << endl;
					cout << "[3]Name Wise" << endl;
					
					if (1 == choice){
						cout << "file1.txt" << endl;
						cout << "file2.cpp" << endl;
						cout << "report.doc" << endl;
						cout << "image.jpg" << endl;
					}
					break;
		}
	}
	while(choice != choice);
}
