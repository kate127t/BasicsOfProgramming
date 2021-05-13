#include<iostream>
#include<fstream>
#include<cstring>
#include"Student.h"
using namespace std;
#define SIZE 30

Student* read_from_file(char* file_name) {
	int size;

	ifstream fin(file_name);

	fin >> size;
	fin.get();
	Student* university = new Student[size];

	for (int i = 0; i < size; i++) { //Get information!
		fin.getline(university[i].LastName, SIZE, ',');
		fin.getline(university[i].FirstName, SIZE, ',');
		fin.getline(university[i].Group, SIZE, ',');
		fin >> university[i].Year;
		fin.getline(university[i].Group, 3, ',');
		fin.getline(university[i].StudNum,SIZE);
	}

	fin.close();

	return university;
}

void sort(Student* university, int size) {
	bool swapped;
	for (int j = 0; j < size; j++) { //by year
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (university[i + 1].Year < university[i + 1].Year) {
				swap(university[i], university[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}

}

void write_to_file(char* file_name, Student* university, int size) {
	ofstream fout(file_name);

	for (int i = 0; i < size; i++) {
		fout << university[i].LastName << ' ' << university[i].FirstName << ',' << university[i].Year << ',' << university[i].Group << ',' << university[i].StudNum << endl;
	}

	fout.close();
}

Student* long_lastname(Student* university, int size){
	Student* long_name = &university[0];
	int long_name_len = strlen(university[0].LastName);
	for (int i = 0; i < size; i++) {
		if (strlen(university[i].LastName) > long_name_len) {
			long_name = &university[i];
			long_name_len = strlen(university[i].LastName);
		}
	}
	return long_name;
}

void main() {
	Student* university;

	int size;
	ifstream fin("students_before.txt");
	fin >> size;
	fin.close();

	const char* name1 = "students_before.txt";
	char* file_name1 = new char[100];
	strcpy_s(file_name1, 100, name1);

	university = read_from_file(file_name1);

	const char* name2 = "students_after.txt";
	char* file_name2 = new char[100];
	strcpy_s(file_name2, 100, name2);

	sort(university, size);

	write_to_file(file_name2, university, size);

	Student long_name = *long_lastname(university, size);
	cout << "Student with the longest last name is: " << endl;
	cout << long_name.LastName << ' ' << long_name.FirstName << ',' << long_name.Year << ',' << long_name.Group << ',' << long_name.StudNum << endl;
}