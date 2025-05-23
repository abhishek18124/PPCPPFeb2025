#include<iostream>

using namespace std;

// time : O(m+n)

bool isPresent(int mat[][10], int m, int n, int t) {

	int i = 0;
	int j = n - 1;

	while (i < m and j >= 0) {

		if (mat[i][j] == t) {
			return true;
		} else if (t > mat[i][j]) {
			i++;
		} else {
			// t < mat[i][j]
			j--;
		}

	}

	return false;

}

int main() {

	int mat[][3] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 50;

	isPresent(mat, m, n, t) ? cout << t << " found" << endl : cout << t << " not found" << endl;

	return 0;
}