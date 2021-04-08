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

int linear_search(int* arr, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

int check_if_anagram(int* arr1,int *arr2,int n) {
	for (int i = 0; i < n; i++) {
		if (linear_search(arr2, n, arr1[i]) == -1) {
			return -1;
		}
	}
	return 1;
}

void main() {
	int n;
	int* arr1, * arr2;
	int k;

	cout << "Enter size of arrays n = ";
	cin >> n;

	arr1 = new int[n];
	arr2 = new int[n];
	read_array(arr1, n);
	read_array(arr2, n);

	print_array(arr1, n);
	print_array(arr2, n);

	k = check_if_anagram(arr1, arr2, n);
	if (k == -1) {
		cout << "Not anagrams";
	}
	if(k == 1){
		cout << "arr1 and arr2 are anagrams.";
	}
}