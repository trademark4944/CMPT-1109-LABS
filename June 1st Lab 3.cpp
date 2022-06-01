#include <iostream>
#include <string>
using namespace std;

/* for (int i = 0; i < size; i++) {
	for (int j = 0; j <= i; j++) {
		cout << char;
	}

for (int i = 0; i < size; i++) {
	for (int j = 1; j <= (size - 1); j++) {
		cout << "_";
	for (int n = 0; n <= i; n++) {
		cout << char;


	height = size
	length = (size*2) - 1;
	array [height, length]

	for (int h = 0; h < height; h++) {
		for (int k = 0; k < length; k++) {
} */

void drawTriangle(int size, char symbol) {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= (size - i); j++) {
			cout << " ";
		}
		for (int k = 0; k < i; k++) {
			cout << symbol;
		}
		for (int n = 1; n < i; n++) {
			cout << symbol;
		}
		cout << endl;
	}
	return;
}
void drawLeftTriangle(int size, char symbol) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cout << symbol;
		}
		cout << endl;
	}
	return;
}

void drawRightTriangle(int size, char symbol) {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= (size - i); j++) {
			cout << " ";
			
		}
		for (int n = 1; n <= i; n++) {
				cout << symbol;
		}
		cout << endl;
	}
	return;
}

void drawDiamond(int size, char symbol) {

}

int main() {
	int size, choice;
	char symbol;
	bool cont = true;

	while (cont == true) {
		cout << "Make selection: draw triangle(1) draw diamond(2) quit(3)  ";
		cin >> choice;

		switch (choice){
			case 1:
				cout << "Input size of shape: ";
				cin >> size;
				cout << "Input desired character: ";
				cin >> symbol;
				drawTriangle(size, symbol);
				break;
			case 2:
				cout << "Input size of shape: ";
				cin >> size;
				cout << "Input desired character: ";
				cin >> symbol;
				drawDiamond(size, symbol);
				break;
			case 3:
				cout << endl << "Program Exiting..." << endl;
				cont = false;
				break;
			default: 
				cout << "ERROR: Invalid Input" << endl;
				break;
		}
	}

	return 0;
}