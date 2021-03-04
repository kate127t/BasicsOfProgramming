#include<iostream>
using namespace std;

void main() {
	int n;
	int x;
	int a;
	int min, max;

	do {
		cout << "Enter n > 0 : ";
		cin >> n;
	} while (n <= 0);

	cout << "a1 = ";
	cin >> a;
	
	min = a;
	max = a;

	for (int i = 2; i <= n; i++) {
		cout << "a" << i << " = ";
		cin >> a;
		if (a > max) {
			max = a;
		}
		if (a < min) {
			min = a;
		}
	}
	cout << "min = " << min;
	cout << "max = " << max;
	cout << "the sum is: " << min + max;

}