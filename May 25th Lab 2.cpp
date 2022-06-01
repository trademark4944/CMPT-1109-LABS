#include <iostream>

using namespace std;

char capitalization(char letter) {
	int code; 

	code = letter; //97 = 'a'

	if (code > 96) {
		code -= 32;
	}

	letter = static_cast<char>(code);

	return letter;
}

int main() {
	char letterGrade;

	cout << "Enter your letter Grade: ";
	letterGrade = getchar();

	letterGrade = capitalization(letterGrade);

	switch (letterGrade) {
	case 'A':
		cout << "Excellent, you need not take the final." << endl;
		break;

	case 'B':
		cout << "Very good, your grade is now an A." << endl;
		break;

	case 'D':
		cout << "Not good, you should go study." << endl;
		break;

	case 'E': 
		cout << "This is not a possible grade" << endl;
		break;

	default: 
		cout << "ERROR: Not a valid input" << endl;
		break;
	}

	cout << endl << "END PROGRAM";

	return 0;
}
