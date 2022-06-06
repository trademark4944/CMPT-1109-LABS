#include <iostream>
using namespace std;

/*int sum = 0;
	for (int j = 0; j < size; j++) {
		sum += arr[j];
	}

	cout << endl << "Sum of inputs is " << sum << endl;*/

int main() {
	int array[100];
	int size, value, minimum = 0, maximum = 0, choice, sum = 0, location = 0;
	bool cont = true, found = false;

	cout << "Input desired number of values in array: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cout << "Input value: ";
		cin >> value;
		array[i] = value;
	}

	while (cont == true) {
		cout << endl << "What operation would you like to perform? sum(1) minimum(2) maximum(3)  search(4) exit(5) ";
		cin >> choice;

		switch (choice) {
		case 2:
			for (int k = 0; k < size; k++) {
				if (k == 0) {
					minimum = array[k];
				}
				else {
					if (value < minimum) {
						minimum = array[k];
					}
				}
			}
			cout << endl << "The minimum of the inputs is " << minimum << endl;
			break;

		case 1:
			for (int j = 0; j < size; j++) {
				sum += array[j];
			}
			cout << endl << "Sum of inputs is " << sum << endl;
			break;

		case 3:
			for (int k = 0; k < size; k++) {
				if (k == 0) {
					maximum = array[k];
				}
				else {
					if (value > maximum) {
						maximum = array[k];
					}
				}
			}
			cout << endl << "The maximum of the inputs is " << maximum << endl;
			break;

		case 5:
			cout << endl << "Program exitting..." << endl;
			cont = false;
			break;

		case 4:
			cout << endl << "Input desired value: ";
			cin >> value;

			for (int a = 0; a < size; a++) {
				if (array[a] == value) {
					found = true;
					break;
				}
				location++;
			}
			if (found == true) {
				cout << endl << value << " is found at location " << location << " within the array" << endl;
			}
			else if (found == false) {
				cout << endl << value << " is not found within the array" << endl;
			}
			location = 0;
			break;

		default:
			cout << endl << "ERROR: Incorrect input" << endl;
			break;

		}
	}

	return 0;
}