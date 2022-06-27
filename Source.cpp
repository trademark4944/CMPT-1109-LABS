#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inputFunction() {
	ofstream file;
	char array[5];

	cout << "input characters: ";
	for (int i = 0; i < 5; i++) {
		cin >> array[i];
	}

	file.open("file.txt");
	for (int j = 0; j < 5; j++) {
		file << array[j];
	}
	file.close();
}

void outputFunction() {
	ifstream file;
	char array[5];
	file.open("file.txt");
	for (int i = 0; i < 5; i++) {
		file >> array[i];
	}
	file.close();

	for (int j = 0; j < 5; j++) {
		cout << array[j] << ' ';
	}
}

int main() {
	bool selection = true;
	char input;
	cout << "input(1) output(0): ";
	cin >> input;

	switch (input){
	case '1':
		selection = true;
		break;

	case '0':
		selection = false;
		break;

	default:
		cout << "ERROR: invalid selection";
		break;
	}
	
	if (selection == true) {
		inputFunction();
	}
	else if (selection == false) {
		outputFunction();
	}
	return 0;
}

/*ifstream file;
	string words;
	file.open("file.txt");
	while (file >> words) {
		cout << words << " ";
	}
	file.close();*/

/*	string words;;
	ofstream file;
	cout << "input string: ";
	getline(cin, words);
	
	file.open("file.txt");
	file << words;
	file.close();*/