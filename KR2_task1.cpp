#include<iostream>
using namespace std;

void read_array(int* arr, int n) {
	int m;
	cout << "How do you want to fill your array?" << endl;
	cout << "1. From the keyboard" << endl;
	cout << "2. Random numbers." << endl;
	do {
		cout << "Enter 1 or 2 : ";
		cin >> m;
	} while (m != 1 && m != 2);
	if (m == 1) {		//From the keyboard
		for (int i = 0; i < n; i++) {
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	}
	else {			//Random numbers
		int random;
		cout << "Enter any random number : ";
		cin >> random;
		srand(random); //Inputting random starting number
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
	}
}

void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "   ";
	}
	cout << endl;
}

void insert_el(int* arr, int n,int p_cur,int p_new) {
	int k = arr[p_cur];
	for (int i = p_cur; i >= p_new; i--) {
		arr[i + 1] = arr[i];
	}
	arr[p_new] = k;
}

void swap_el() {
	int n;
	int last_not_even = 0;
	cout << "Enter size of array, n = ";
	cin >> n;
	int* arr = new int[n];
	read_array(arr, n);
	print_array(arr, n);

	for (int i = 1; i < n; i++) {
		if (arr[i] % 2 != 0) {
			insert_el(arr, n, i, last_not_even);
			print_array(arr, n);
			last_not_even = i+1;
		}
		
	}
	print_array(arr, n);
}

void main() {
	swap_el();
}