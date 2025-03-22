#include<iostream>

using namespace std;

int main() {

	char ch1;
	cin >> ch1;
	cout << ch1 << endl;
	cout << (int)ch1 << endl;

	char ch2;
	ch2 = 'A';
	cout << ch2 << endl;
	cout << (int)ch2 << endl;

	char ch3 = 'z';
	cout << ch3 << endl;
	cout << (int)ch3 << endl;

	char ch4 = '0';
	cout << ch4 << endl;
	cout << (int)ch4 << endl;

	// to convert a digit in char form to digit in int form
	// subtract '0' from the given digit, internally ascii
	// values will be subtracted and you'll get the desired
	// output

	char ch5 = '7';
	cout << (int)ch5 << endl;
	cout << ch5 - '0' << endl;

	char ch6 = 65; // implicit type-casting is done, A is stored in ch6
	cout << ch6 << endl;

	return 0;
}