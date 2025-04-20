#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	string str;

	// getline(cin, str);

	// getline(cin >> ws, str);

	// cin >> ws is an i/p manipulator that can be used to ignore leading whitespaces

	getline(cin >> ws, str, '$');

	cout << str << endl;

	return 0;
}