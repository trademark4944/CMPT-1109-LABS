#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream mainFile;
	bool fileOpen = true;
	char chars;
	string string;
	int counter = 0;

	while (counter < 2) {
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
