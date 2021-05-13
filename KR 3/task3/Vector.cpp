#include"Vector.h"

Vector::Vector(int a1, int a2) {
	x = a1;
	y = a2;
}

int Vector::Len_vector() {
	return sqrt(x * x + y * y);
}