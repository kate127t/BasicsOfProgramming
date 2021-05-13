#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
#define SIZE 30

char** read_from_file(char* filename) {
	int size;

	ifstream fin(filename);

	fin >> size;
	fin.get();
	
	char** students = new char* [size];

	for (int i = 0; i < size; i++) { //Get information!
		fin.getline(students[i], SIZE);
	}

	fin.close();

	return students;
}

char** only_prog(char** prog, int size1, char** history, int size2) {
	bool is_only_prog = true;
	
	char** only_prog = new char* [size1];
	int k = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			if (prog[i] == history[j]) {
				is_only_prog = false;
			}
		}
		if (is_only_prog == true) {
			only_prog[k++] = prog[i];
		}
	}
	
	char** result = new char* [k-1];

	for (int j = 0; j < k - 1; j++) {
		strcpy_s(result[j], SIZE, only_prog[j]);
		cout << result[j];
	}
	delete[] only_prog;
	return result;
}

void main() {
	int size1,size2;

	ifstream fin("in1.txt");
	fin >> size1;
	fin.close();

	ifstream fin("in2.txt");
	fin >> size2;
	fin.close();

	const char* name1 = "in1.txt";
	char* filename1 = new char[100];
	strcpy_s(filename1, 100, name1);

	const char* name2 = "in2.txt";
	char* filename2 = new char[100];
	strcpy_s(filename2, 100, name2);

	char** prog = read_from_file(filename1);
	char** history = read_from_file(filename2);

	char** only_programming = only_prog(prog, size1, history, size2);
}
