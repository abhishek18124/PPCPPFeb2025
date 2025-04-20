#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcabc";
	string t = s.substr(3, 4); // starting index, length
	cout << t << endl;

	cout << s.substr(5) << endl;
	// cout << s.substr(5, 100) << endl;

	return 0;
}