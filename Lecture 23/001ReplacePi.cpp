/*

Given string str of size n, design a recursive algorithm to replace all
occurrences of "pi" with "3.14" in the given string and then print it.

Example :
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

Constraints :

	1 < n < 10

*/

#include<iostream>

using namespace std;

void f(char inp[], int i) {

	// base case

	if (inp[i] == '\0') {
		// cout << inp << endl; // optional
		return; // mandatory return stmt
	}

	// recursive case

	// f(i) = it is fn that replaces all the "pi" with "3.14"
	// in inp[i...n-1] (suffix of inp[] that starts at idx i)

	if (inp[i] == 'p' and inp[i + 1] == 'i') {

		// 1. replace "pi" at the (i, i+1)th index with "3.14"

		// 1a. shift all the char. starting from index i+2 2-steps forward

		int j = i + 2;
		while (inp[j] != '\0') {
			j++;
		}

		// once above loop finishes j contains the index of '\0' character

		while (j >= i + 2) {
			inp[j + 2] = inp[j];
			j--;
		}

		// 1b. do the replacement

		inp[i] = '3';
		inp[i + 1] = '.';
		inp[i + 2] = '1';
		inp[i + 3] = '4';

		// 2. ask your friend to replace all the "pi" with "3.14" in
		// inp[i+4] (suffix of inp[] that starts at the i+4th index)

		f(inp, i + 4);

	} else {

		// ask your friend to replace "pi" with "3.14"
		// in inp[i+1...n-1] (suffix that starts at i+1)

		f(inp, i + 1);

	}

	return; // optional return stmt

}

int main() {

	char inp[20] = "ipiippii";

	f(inp, 0);

	cout << inp << endl;

	return 0;
}
