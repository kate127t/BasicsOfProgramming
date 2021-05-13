#include<iostream>
#include"Vector.h"
using namespace std;

void main() {
	int a1, a2;
	cout << "Enter a1: ";
	cin >> a1;
	cout << "Enter a2: ";
	cin >> a2;

	Vector a =  Vector(a1, a2);
	int len = a.Len_vector();
}