/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal that starts at the i,jth index

	while (i < m and j < n) {
		cout << mat[i][j] << " ";
		i++;
		j++;
	}

	cout << endl;

}

void printDiagonal2(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal that starts at the i,jth index

	int len = min(m - i, n - j);

	for (int k = 0; k < len; k++) {
		cout << mat[i + k][j + k] << " ";
	}

	cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// iterate over starting points of diagonals

	// 1. print diagonals that start at (i, 0)

	for (int i = 0; i < m; i++) {
		// printDiagonal(mat, m, n, i, 0);
		printDiagonal2(mat, m, n, i, 0);
	}

	// 2. print diagonals that starts at (0, j)

	for (int j = 1; j < n; j++) {
		// printDiagonal(mat, m, n, 0, j);
		printDiagonal2(mat, m, n, 0, j);
	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);

	return 0;
}