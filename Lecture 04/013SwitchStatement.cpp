#include<iostream>

using namespace std;

int main() {

	char grade;
	cin >> grade;

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "avg." << endl;
	// } else if (grade == 'D') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'E') {
	// 	cout << "very poor" << endl;
	// } else {
	// 	cout << "fail" << endl;
	// }

	// if you don't break from a matched case you'll go to the next case

	switch (grade) { // you can only switch int / char
	case 'A': cout << "very good" << endl; break;
	case 'B': cout << "good" << endl; break;
	case 'C': cout << "avg" << endl; break;
	case 'D': cout << "poor" << endl; break;
	case 'E': cout << "very poor" << endl; break;
	default: cout << "fail" << endl; break; // break in default case is optional
	}

	return 0;
}