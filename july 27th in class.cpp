#include <iostream>
using namespace std;

int factR(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else if (n < 0) {
		return -1;
	}
	else {
		return (n * factR(n - 1));
	}
}

int fact(const int n) {
	int total = 1;
	for (int i = 1; i <= n; i++) {
		total *= i;
	}
	return total;
}

int fibR(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return fibR(n - 1) + fibR(n - 2);
	}
}

int fib(const int n) {
	int arr[100];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n-1];
}

void f1(int arr[], int size_) {
	if (size_ > 0) {
		cout << arr[size_ - 1] << " ";
		f1(arr, (size_ - 1));
	}
}

void f2 (int arr[], int size_) {
	for (int i = 0; i < size_; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = { 1,2,3,4,5 };
	f1(arr, 5);
	f2(arr, 5);
	return 0;
}
/*int n = 0, total = 1;
	cout << "Enter number: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		total *= i;
	}

	cout << total;*/
