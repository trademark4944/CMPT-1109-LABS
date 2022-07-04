#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
fstream mainFile;

bool isOpen() {
	bool fileOpen;
	if (mainFile.is_open()) {
		fileOpen = true;
	}
	else {
		cout << "ERROR: Unable to Open File." << endl;
		fileOpen = false;
	}
	return fileOpen;
}

string getAnswer(bool &fileOpen, int counter) {
	char chars;
	string string;
	int i = 0;

	while (i < counter) {
		mainFile.ignore(100, '.');
		i++;
	}

	while (fileOpen) {
		mainFile.get(chars);
		if (chars == '.') {
			mainFile.close();
			fileOpen = mainFile.is_open();
		}
		else {
			string += chars;
		}
	}

	return string;
}

void writeAnswer(bool &fileOpen, string answer) {
	mainFile << answer << "\n";
	mainFile.close();
	fileOpen = mainFile.is_open();
}

int main() {
	bool isOutput, fileOpen = true;
	string question, answer;
	int counter = 0;

	while (question != "0") {
		cout << "Enter a question or 0 to exit: ";
		cin >> question;
		counter++;
		for (int i = 0; i < counter; i++) {
			mainFile.ignore(500, '.');
		}
		mainFile.open("answers.txt");
		fileOpen = isOpen();

		if (fileOpen == true) {
			answer = getAnswer(fileOpen, counter);
		}
		else {
			return 0;
		}
		writeAnswer(fileOpen, answer);
		
	}

	return 0;
}

/*fstream mainFile;
	bool fileOpen = true;
	char chars;
	string string;
	int counter = 0;

	while (counter < 5) {
		mainFile.open("answers.txt");
		fileOpen = true;
		for (int i = 0; i < counter; i++) {
			mainFile.ignore(500, '.');
		}
		while (fileOpen) {
			mainFile.get(chars);
			if (chars == '.') {
				fileOpen = false;
			}
			else if (!mainFile.eof()) {
				string += chars;
			}
			else {
				fileOpen = false;
			}
		}
		counter++;
		mainFile.close();

		mainFile.open("file.txt");
		mainFile << string;
		mainFile.close();
	}

	return 0;*/
