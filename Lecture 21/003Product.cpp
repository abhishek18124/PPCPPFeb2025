#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) = a fn that finds prodt of x and 0
		// i.e. adds x, 0 times
		return 0;
	}

	// recursive case

	// f(x, y) =  it is a fn that finds the prodt of x and y i.e. adds x, y times

	// 1. ask your friend to find the prodt of x and y-1 i.e.
	// ask your friend to add x, y-1 times

	int A = f(x, y - 1);

	return x + A;

}

int main() {

	int x = 2;
	int y = 3;

	cout << f(x, y) << endl;

	return 0;
}