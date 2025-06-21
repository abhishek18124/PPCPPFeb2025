#include<iostream>

using namespace std;

int f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) return 0; // you've gone outside the maze[][]
	if (maze[i][j] == 'X') return 0; // you've reached a blocked cell
	if (i == m - 1 and j == n - 1) return 1; // you've reach the destination cell therefore you've found path

	// recursive case

	// f(i, j) : find no. of paths from i,jth cell m-1,n-1th cell

	// decide the next step

	// option1 : move right

	// option2 : move down

	return f(maze, m, n, i, j + 1) + f(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	cout << f(maze, m, n, 0, 0) << endl;

	return 0;
}