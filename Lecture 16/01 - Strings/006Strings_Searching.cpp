#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcabc";
	cout << s.find("ca") << endl;
	cout << s.rfind("ca") << endl;
	cout << s.find("abca") << endl;
	cout << s.find("bcabc") << endl;
	cout << s.find("xyz") << endl;
	cout << string::npos << endl;
	cout << (string::npos == -1) << endl;

	return 0;
}