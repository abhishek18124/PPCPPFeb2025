#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr; // pointer declaration // by default it contains garbage addr hence it is a.k.a wild pointer
	xptr = &x; // pointer assignment

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << "B" << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl << endl;

	double y = 3.14;
	double* yptr = &y; // pointer initialisation

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << "B" << endl;
	cout << "&y = " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << "B" << endl << endl;

	char ch = 'A';
	char* chptr = &ch;

	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << "B" << endl;
	cout << "&ch = " << &ch << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;
	cout << "chptr = " << chptr << endl;
	cout << "sizeof(chptr) = " << sizeof(chptr) << "B" << endl;


	return 0;
}