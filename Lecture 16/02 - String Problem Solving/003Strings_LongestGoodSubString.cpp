#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}
	}

	return true;

}

// time : O(n^3)

int longestGoodSubstring(const string& str) {

	int maxSofar = 0;

	int n = str.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSofar = max(maxSofar, j - i + 1);
			}
		}
	}

	return maxSofar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}