#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

void ListofFiles(){
	if(fs:: exist(path) && fs::directory(path)){
		cout << "Files "
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
