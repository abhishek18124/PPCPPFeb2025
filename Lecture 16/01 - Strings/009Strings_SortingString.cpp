#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "bcaab";

	sort(s.begin(), s.end());

	cout << s << endl;

	// sort(s.rbegin(), s.rend());
	sort(s.begin(), s.end(), greater<char>());

	cout << s << endl;

	return 0;
}