#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == -1 or j == -1 or i == m or j == n) {
		return;
	}

	if (maze[i][j] == 'X') {
		return;
	}

	if (i == m - 1 and j == n - 1) {
		path[i][j] = '1';
		printPath(path, m, n);
		return;
	}

	// recursive case

	if (path[i][j] == '1') { // i,jth cell is already part of the path under construction so we cannot use it again
		return;
	}

	path[i][j] = '1';
	maze[i][j] = 'X';
	f(maze, path, m, n, i, j + 1); // move right
	f(maze, path, m, n, i + 1, j); // move down
	f(maze, path, m, n, i, j - 1); // move left
	f(maze, path, m, n, i - 1, j); // move up
	path[i][j] = '0'; // backtracking
	maze[i][j] = '0'; // backtracking

}

int main() {

	char maze[][10] = {
		"0X00",
		"000X",
		"X0X0",
		"X00X",
		"XX00"
	};

	char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
