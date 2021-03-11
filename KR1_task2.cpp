#include<iostream>
using namespace std;

int product_calc(int k) {
	int prod = 1;
	do
	{
		prod *= k % 10;
		k = k / 10;

	} while (k % 10 != 0);
	return prod;
}

int check_if_divided_2to9(int n) {
	for (int i = 2; i <= 9; i++) {
		if (n % i == 0)
			return n / i;
	}
	return 0;
}

int check_if__there_can_be_k(int n) {
	if (n == 1)
		return 0;
	else {
		do {
			n = check_if_divided_2to9(n);
		} while (n != 0 && n != 1);
		if (n == 0)
			return 1;
		if (n == 1)
			return 0;
	}
}


int check_product(int n) {
	int prod = 1;
	int k = 1;
	while (prod != n) {
		k++;
		prod = product_calc(k);
		if (prod == n)
			return k;
	}
}

void main() {
  int n,min_k;
  
  do {
		cout << "Enter n (n>0) : ";
		cin >> n;
  } while (n <= 0);

  if (check_if__there_can_be_k(n) == 1)
	  cout << "There is no such k";
  else {
	  min_k = check_product(n);
	  cout << "tme min k is : " << min_k;
  }
}