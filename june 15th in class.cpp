#include <iostream>
using namespace std;

int main() {
	int targetInteger, length, indiceOne, indiceTwo, holder;
	int integerSelection[20];
	bool cont = true, foundIndices = false;

	while (cont == true) {
		cout << endl << "Input target integer: ";
		cin >> targetInteger;

		cout << endl << "Input number of selection integers: ";
		cin >> length;

		cout << endl << "Input selection integers seperated by one \" \": ";
		for (int i = 0; i < length; i++) {
			cin >> integerSelection[i];
		}

		for (int n = 0; n < length; n++) {
			for (int x = 0; x < length; x++) {
				if (x == n) {
					continue;
				}
				else if (integerSelection[n] + integerSelection[x] == targetInteger) {
					indiceOne = n;
					indiceTwo = x;
					foundIndices = true;
					break;
				}
				else {
					continue;
				}
			}
			if (foundIndices == true) {
				break;
			}
		}

		if (foundIndices == true) {
			cout << endl << "Integers at indice " << indiceOne << " and indice " << indiceTwo << " sum to the target integer " << targetInteger << ". " << endl;
		}
		else if (foundIndices == false) {
			cout << endl << "No provided integer selections sum to the target integer" << endl;
		}

		cout << endl <<  "Continue program? yes(1) no (0): ";
		cin >> cont;
		cout << "-------------------------------------------------" << endl;
	}

	cout << endl << "Exitting..." << endl;
	return 0;
}