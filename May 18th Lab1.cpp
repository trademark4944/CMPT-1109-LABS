#include <iostream>
#include <math.h>

using namespace std;

int main() {

	double a, b, c, d, x1, x2;
	int boolean;
	bool cont = true;

	cout << "Solving Quadratics of form 'ax^2 + bx + c'" << endl;

	while (cont == true) {
		cout << "Enter value for a: ";
		cin >> a;

		cout << "Enter value for b: ";
		cin >> b;

		cout << "Enter value for c: ";
		cin >> c;

		cout << endl;

		if ((a == 0 && b == 0) || a == 0) {
			cout << "ERROR: Not a Quadratic" << endl;
		}

		else {
			d = pow(b, 2) - (4 * a * c);

			if (d < 0) {
				cout << "ERROR: No real answer" << endl;
			}

			else {
				x1 = (-b + sqrt(d)) / (2 * a);

				x2 = (-b - sqrt(d)) / (2 * a);

				if (x1 == x2) {
					cout << "The root of '" << a << "x^2 + " << b << "x + " << c << "' is " << x1 << endl;
				}

				else {
					cout << "The roots of '" << a << "x^2 + " << b << "x + " << c << "' are " << x1 << " and " << x2 << endl;
				}

				cout << endl;
			}
		}

		cout << "Terminate? (0) Continue? (1) " << endl;
		cin >> boolean;

		if (boolean == 0) {
			cont = false;
		}

		cout << endl;
	}

	return 0;

}