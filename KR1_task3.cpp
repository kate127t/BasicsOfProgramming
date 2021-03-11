#include<iostream>
using namespace std;

int element(int i) {
	int ai_2 = 1;
	int ai_1 =  -1;
	int ai;

	if (i == 0)
		return 1;
	if (i == 1)
		return -1;

	for (int j = 2; j <= i; j++) {
		ai = -ai_1 + 4 * ai_2 * ai_2 + 1;
		ai_2 = ai_1;
		ai_1 = ai;
	}
	return ai;
}

int sum_of_elements(int N) {
	if (N == 1) {
		return element(N-1);
	}
	else {
		return sum_of_elements(N - 1) + element(N - 1);
	}
}

void main() {
	int N;

	do {
		cout << "Enter N (N>0) : ";
		cin >> N;
	} while (N <= 0);

	cout << "The sum of " << N << " first elements is: " << sum_of_elements(N);

}