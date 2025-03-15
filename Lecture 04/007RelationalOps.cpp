#include<iostream>

using namespace std;

int main() {

	int a = 10;
	int b = 5;

	cout << "a > b : " << (a > b) << endl; // true
	cout << "a >= b : " << (a >= b) << endl; // true
	cout << "a < b : " << (a < b) << endl; // false
	cout << "a <= b : " << (a <= b) << endl; // false
	cout << "a == b : " << (a == b) << endl; // false
	cout << "a != b : " << (a != b) << endl; // true

	return 0;
}