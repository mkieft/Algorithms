#include <iostream>
#include <fstream> //to open file
using namespace std;

int main() {
	ifstream inFile; 
	string names;

	inFile.open("app_c.csv");
	if (inFile.is_open()) {
		cout << "File opened" << endl;
	}
	else {
		cout << "NO FILE OPENED" << endl;
	}

	while (!inFile.eof()) {
		getline(inFile, names);
		cout << " Name: " << names << endl;
	}



	return 0;
}