/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

// 1. whenever for a single decision you've more than 2 options
// there always will be in the loop in the rec. case to iterate
// over the options

// 2. whevern for a single decision you've multiple options (>=2 )
// there always will be backtracking

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case
	if (i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) : take decisions for remaining positions i to n-1

	// decide for the ith position

	for (int j = i; j <= n - 1; j++) {
		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking // undo
	}

}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
