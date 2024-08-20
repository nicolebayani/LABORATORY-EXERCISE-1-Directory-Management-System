#include <iostream>

using namespace std;

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
		cout << "[4]-Exit" << endl; 
		cin >> choice;
	}
	while(choice == choice);
}
