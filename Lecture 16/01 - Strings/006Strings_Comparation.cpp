#include<iostream>
#include<string>

using namespace std;

int main() {

	// string objs can be compared using relational
	// operators and by default they are compared
	// lexicograpically

	string s = "zbc";
	string t = "zbc";

	if (s > t) {
		cout << "s > t" << endl;
	} else if (s < t) {
		cout << "s < t" << endl;
	} else {
		cout << "s equal to t" << endl;
	}

	return 0;
}