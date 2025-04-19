// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	// cin >> str;

	// when you use cin>> to a string,
	// cin>> stops reading i/p as soon as it encounters a whitespace character

	// cin.getline(str, 101);

	// cin.getline(str, 5);

	// cin.getline(str, 9);

	// cin.getline(str, 101, '$'); // '$' is known as delimiting character

	cin.getline(str, 5, '#');

	cout << str << endl;

	return 0;
}