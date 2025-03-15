#include<iostream>

using namespace std;

int main() {

	cout << "true && true : " << (true && true) << endl; // true
	cout << "true && false : " << (true && false) << endl; // false
	cout << "false && true : " << (false and true) << endl; // false
	cout << "false && false : " << (false and false) << endl; // false

	cout << endl;

	cout << "true || true : " << (true || true) << endl; // true
	cout << "true || false : " << (true || false) << endl; // true
	cout << "false or true : " << (false or true) << endl; // true
	cout << "false or false : " << (false or false) << endl; // false

	cout << endl;

	cout << "!true : " << (!true) << endl; // false
	cout << "!false : " << (!false) << endl; // true

	return 0;
}