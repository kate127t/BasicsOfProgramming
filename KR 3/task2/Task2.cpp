#include<iostream>
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

}