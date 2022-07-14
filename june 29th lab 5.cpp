#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
fstream mainFile;

string chapterNumber(string answer, int& N) {
	char hold = ' ';
	if (N == 0) {
		N = 18;
	}
	else if (N < 10) {
		hold = N + 48;
	}
	else if (N > 9) {
		N -= 10;
		answer += '1';
		hold = N + 48;
		N += 10;
	}
	answer += hold;
	N--;

	return answer;
}

void getAnswer(int counter, int &N) {
	char chars;
	string string;
	int length = 0;

	for (int i = 0; i < counter; i++) {
		mainFile.open("answers.txt");

		for (int j = 0; j < i; j++) {
			mainFile.ignore(300, '.');
		}
		while (mainFile.is_open()) {
			mainFile.get(chars);
			if (chars == '.') {
				mainFile.close();
			}
			else if (chars == '\n') {
				continue;
			}
			else {
				string += chars;
			}
		}

		length = string.length() - 1;
		if (string.at(length) == '#') {
			string = chapterNumber(string, N);
		}

		string += '\n';

		mainFile.open("file.txt");
		mainFile << string;
		mainFile.close();

	}
}

int main() {
	string question;
	int counter = 0, N = 18, length, holding, overHolder;

	do {
		cout << "Enter a question or 0 to exit: ";
		cin >> question;
		if (question != "0") {
			counter++;
		}
	} while (question != "0");

	if (counter > 8) {
		holding = counter / 8;
		overHolder = counter - (holding * 8);
		for (int n = 0; n < holding; n++) {
			getAnswer(8, N);
		}

		if (overHolder != 0) {
			getAnswer(overHolder, N);
		}
	}
	else {
		getAnswer(counter, N);
	}

	return 0;
}
