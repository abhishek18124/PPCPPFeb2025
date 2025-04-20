#include<iostream>
#include<string>

using namespace std;

// for a string of size n, it will have n(n+1)/2 substrings
// i.e. ~ n^2 substrings

void generateSubstrings(const string& str, int n) { // by default str obj is passed by value

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// generate the substring that starts
			// at the ith index and ends at the
			// jth index;

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}