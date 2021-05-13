#include"Student.h"
#define SIZE 30

Student::Student() {
	char* LastName  = new char[SIZE];
	char* FirstName = new char[SIZE];
	char* Group = new char[3];
	char* StudNum = new char[SIZE];
}

Student::~Student() {
	delete[] LastName;
	delete[] FirstName;
	delete[] Group;
	delete[] StudNum;
}