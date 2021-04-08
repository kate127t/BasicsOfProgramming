#include<iostream>
using namespace std;


int** create_matrix(int n, int m) {
	int** matrix;
	matrix = new int* [n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	return matrix;
}

void delete_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** input_matrix(int n, int m) {
	int** matrix = create_matrix(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

void output_matrix(int** matrix, int n, int m) {
	cout << "Matrix : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}


void read_array(int* arr, int n) {
	int m;
	cout << "How do you want to fill your array?" << endl;
	cout << "1. From the keyboard" << endl;
	cout << "2. Random numbers." << endl;
	do {
		cout << "Enter 1 or 2 : ";
		cin >> m;
	} while (m != 1 && m != 2);
	if (m == 1) {		//From the keyboard
		for (int i = 0; i < n; i++) {
			cout << "arr[" << i << "] = ";
			cin >> arr[i];
		}
	}
	else {			//Random numbers
		int random;
		cout << "Enter any random number : ";
		cin >> random;
		srand(random); //Inputting random starting number
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
	}
}

void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "   ";
	}
	cout << endl;
}

int sum_el_diagonal(int* diagonal, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += diagonal[i];
	}
	return sum;
}

int* return_diagonal(int** matrix, int n, int i, int j,int up_down) {
	int* diagonal = new int[n];
	//diagonal is above main
	if (up_down == 0){
		do {
			diagonal[i] = matrix[i][j];
			i++;
			j++;
		} while (i < n && j < n);
	}
	//diagonal is below main
	if (up_down == 1) {
		do {
			diagonal[j] = matrix[i][j];
			i++;
			j++;
		} while (i < n && j < n);
	}
	return diagonal;
}

int* find_max_diagonal(int**matrix,int n) {
	int* max_diagonal = new int[n];
	int* cur_diagonal = new int [n];
	int sum_max_diagonal = 0;
	int sum_cur_diagonal = 0;
	//Main diagonal as max_diagonal
	for (int i = 0; i < n; i++) { 
		max_diagonal[i] = matrix[i][i];
	}
	//Getting new diagonal, compare sum with sum_max_diagonal
	for (int j = 0; j < n; j++) {
		cur_diagonal = return_diagonal(matrix, n, 0, j, 0);
		sum_cur_diagonal = sum_el_diagonal(cur_diagonal, n);
		if (sum_cur_diagonal > sum_max_diagonal) {
			max_diagonal = cur_diagonal;
			sum_max_diagonal = sum_cur_diagonal;
		}
		delete[] cur_diagonal;
		sum_cur_diagonal = 0;
	}
	for (int i = 0; i < n; i++) {
		cur_diagonal = return_diagonal(matrix, n, i, 0, 1);
		sum_cur_diagonal = sum_el_diagonal(cur_diagonal, n);
		if (sum_cur_diagonal > sum_max_diagonal) {
			max_diagonal = cur_diagonal;
			sum_max_diagonal = sum_cur_diagonal;
		}
		delete[] cur_diagonal;
		sum_cur_diagonal = 0;
	}
	return max_diagonal;
}

void test_max_diagonal() {
	int n;
	int** matrix;
	int* max_diagonal;
	cout << "Enter size of the matrix (n*n): ";
	cin >> n;
	matrix = input_matrix(n, n);
	max_diagonal = find_max_diagonal(matrix, n);
	print_array(max_diagonal,n);
}

void main() {
	test_max_diagonal();
}