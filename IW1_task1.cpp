#include<iostream>
using namespace std;

void main() {
	int n;
	do {
		cout << "Enter n > 0 : ";
		cin >> n;
	} while (n <= 0);

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << j;
		}
		cout << endl;
	}

}