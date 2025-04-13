#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *xptr = &x;
	cout << "x = " << x << endl;
	cout << "*xptr = " << *xptr << endl << endl;

	double y = 3.14;
	double* yptr = &y;
	cout << "y = " << y << endl;
	cout << "*yptr = " << *yptr << endl << endl;

	char ch = 'A';
	char* chptr = &ch;
	cout << "ch = " << ch << endl;
	cout << "*chptr = " << *chptr << endl << endl;

	return 0;
}