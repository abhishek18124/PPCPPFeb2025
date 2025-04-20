#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ababbaab";

	// time : O(n)

	int rudeness = 0;
	int n = str.size();
	int cntB = 0; // to track no. of b's that we've seen so far

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'b') {
			cntB++;
		} else {
			// str[i] == 'a'
			rudeness += cntB;
		}
	}

	cout << rudeness << endl;


	return 0;
}