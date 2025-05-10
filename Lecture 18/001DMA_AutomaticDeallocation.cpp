#include<iostream>

using namespace std;

int* f() {
	int x = 10;
	return &x;
}

int main() {

	int* xptr = f();

	// cout << *xptr << endl; // avoid this since xptr is a dangling pointer and this behaviour is undefined

	return 0;
}