#include<iostream>

using namespace std;

int* f() {
	int* ptr = new int;
	*ptr = 50;
	return ptr;
}

int main() {

	int* xptr = f();

	cout << *xptr << endl;

	return 0;
}