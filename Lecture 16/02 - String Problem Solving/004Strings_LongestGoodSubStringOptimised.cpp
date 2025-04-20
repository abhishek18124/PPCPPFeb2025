#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	// time : O(n)
	// [HW] try to also print the longest good substring

	int cnt = 0; // to track the length of the longest good substring
	int maxSofar = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			cnt++;
			maxSofar = max(maxSofar, cnt);
		} else {
			cnt = 0 ;
		}

	}

	cout << maxSofar << endl;


	return 0;
}