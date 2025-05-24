#include<iostream>

using namespace std;

int f(int n) {

	// base case

	if (n == 0) {
		// f(0) = it is a fn that tells 0!
		return 1;
	}

	// recursive case

	// f(n) = it is a fn that tells n!

	// 1. ask your friend to find n-1!

	int A = f(n - 1);

	return n * A;

}

int main() {

	int n = 4;

	cout <<	f(n) << endl;

	return 0;
}