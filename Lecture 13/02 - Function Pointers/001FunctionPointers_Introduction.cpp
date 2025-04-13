#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)&add << endl;
	cout << (void*)&ascending << endl << endl;

	// using & to access address of a fn is optional

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl << endl;

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	// using dereference op. to call a fn using a fn ptr is optional

	(*gptr)();
	greet();
	gptr();
	(*greet)();

	cout << add(2, 3) << endl;
	cout << (*add)(2, 3) << endl;
	cout << (*aptr)(2, 3) << endl;
	cout << aptr(2, 3) << endl;

	cout << ascending(5, 7) << endl;
	cout << (*ascptr)(5, 7) << endl;
	cout << ascptr(5, 7) << endl;

	return 0;
}