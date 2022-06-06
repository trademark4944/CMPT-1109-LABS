#include <iostream>
using namespace std;

void drawTriangle(int size, char symbol) { //function which draws triangle with size and symbol taken from inputs from main()

	for (int i = 1; i <= size; i++) { //increments number of lines needed in triangle (the size of the trienagle)
		for (int j = 1; j <= (size - i); j++) { 
			//displays needed spaces at beggining of each line, in order to create a right triangle with it's diagonal on the left 
			cout << " ";
		}
		for (int k = 0; k < i; k++) { //inputs the symbols for this left diagonal triangle
			cout << symbol;
		}
		for (int n = 1; n < i; n++) { //completes the other half of the triangle, creating the diagonal on the right
			cout << symbol;
		}
		cout << endl;
	}
	/*for loops use variable i to determine how many symbols to output, i is dependent on which line is being created
	(eg.line 1 has 1 input and line 2 gets 2 and so forth)*/
	return;
}

void drawDiamond(int size, char symbol) { //function which draws a diamond with size and symbol taken from inputs from main()

	drawTriangle(size, symbol); //calls triangle function as the top half of a diamond is a triangle, less code to write :)

	size--; /*size is decreased by 1 as the middle line of the diamond has already been created when we call drawTriangle(),
			therefore we only need to draw an upside down triangle with 1 less line than the right side up one to finish the diamond*/

	for (int i = 1; i <= size; i++) { 
		/*the following for loops are similar to the for loops in drawTriangle(), only they are reversed 
		instead of incrementing with an increase we increment with a decrease in order to draw an upside down triangle.
		we draw the most ammount of symbols and then the least ammount of symbols thus why we start at the large number and then decrease
		to the small number*/
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int n = size; n >= i; n--) {
			cout << symbol;
		}
		for (int k = (size - 1); k >= i; k--) {
			cout << symbol;
		}
		cout << endl;
	}

	return;
}

int main() {
	int size, choice;
	char symbol;
	bool cont = true;

	while (cont == true) { //while loop to continue the function until user decides to exit program

		cout << "Make selection: draw triangle(1) draw diamond(2) quit(3)  "; 
		
		/*variable choice and the switch case loop determines what the user wants to accomplish, the loop calls respective functions for each
		task the user requests, it also gathers needed inputs for each function*/
		
		cin >> choice;

		switch (choice) {
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
