#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* ptr1 = &x; // ptr to int
	const int* ptr2 = &x; // ptr to const-int

	cout << *ptr1 << " " << *ptr2 << endl;

	(*ptr1)++;

	cout << *ptr1 << " " << *ptr2 << endl;

	// (*ptr2)++; // error : since ptr2 points to a const int

	int* const ptr3 = &x; // const ptr to int

	(*ptr3)++;

	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;

	const int* const ptr4 = &x; // const ptr to const-int

	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << " " << *ptr4 << endl;

	return 0;
}