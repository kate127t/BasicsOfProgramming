#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define SIZE 100

bool check_word(char* word, int len_w) {
	for (int i = len_w; i > 0; i--) {
		if (!is_alpha((int)word[i]) {
			return false;
		}
	}
	return true;
}

char* delete_words_with_symbols(char* str,int len) {
	char* new_str = new char[SIZE];
	char* word = new char[SIZE];
	int k = 0;
	int j = 0;
	for (int i = strlen(str); i>0; i--) {
		word[j++] = str[i];
		if (str[i] = ' ') {
			if (check_word) {
				for (int i = 0; word[i] != '\0'; i++) {
					new_str[k++] = word[i];
				}
				i = 0;
				delete[]word;
				char* word = new char[SIZE];
			}
		}
	}
}

void main() {
	ifstream fin("string_before.txt");
	char* str = new char[SIZE];
	char* new_str = new char[SIZE];
	char ch;
	int i = 0;

	fin.getline(str, SIZE);
	/*
	do {
		fin >> ch;
		str[i] = ch;
		i++;
	} while (ch != '.');
	str[i] = '\0';
	*/
	fin.close();

	cout << "the string before changes: " << str << endl;
	cout << "what symbol do you want to delete from the string? ";
	cin >> ch;

	new_str = delete_symbol_from_string(str, ch);
	cout << "the string after changes: " << new_str << endl;

	ofstream fout;
	fout.open("string_after.txt");

	i = 0;
	while (new_str[i] != '\0') {
		fout << new_str[i++];
	}

	fout.close();
}