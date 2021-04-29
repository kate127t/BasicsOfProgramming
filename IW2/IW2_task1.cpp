#include<iostream>
using namespace std;
#define SIZE 100

char* delete_digits(char* str) {
	char* new_str = new char[SIZE];
	char previous;
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if ('0' < str[i] < '9' && str[i] ==previous) {
			break;
		}
		new_str[j] = str[i];
		j++;
		previous = str[i];
	}
}

void test() {
	char* str = new char[SIZE];
	char* new_str = new char[SIZE];
	char ch;

	cout << "Enter the string you want to change: ";
	cin.getline(str, SIZE);

	cout << "The string before changes: " << str << endl;
	new_str = delete_digits(str);
	cout << "The string after changes: " << new_str << endl;
	delete[] str;
	delete[] new_str;
}

void main() {
	test();
}