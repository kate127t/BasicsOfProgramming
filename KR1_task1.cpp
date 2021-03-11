#include<iostream>
using namespace std;

void main() {
	int n,x;
	float sum = 0, el = 0;

	do {
		cout << "Enter n (n>0) : ";
		cin >> n;
	} while (n <= 0);

    do {
		cout << "Enter x (0 <= x <= 9) : ";
		cin >> x;
	} while (x<0 || x>9);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			el += x * (pow(0.1, j));
			//cout << el << endl;
		}
		sum += el;
		el = 0;
	}
	cout << "The sum is : " << sum;

	
}