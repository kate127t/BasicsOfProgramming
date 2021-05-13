#pragma once
#include<iostream>
using namespace std;
#define SIZE 30

struct Student {
	char* LastName;
	char* FirstName;
	int Year;
	char* Group;
	char* StudNum;
	Student();
	~Student();
};
