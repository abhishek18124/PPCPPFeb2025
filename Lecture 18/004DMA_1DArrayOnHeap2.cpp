#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// allocate memory for a 1D array with custom size on the heap

	int* ptr = new int[n]; // size can be given at runtime while creating array on heap

	// read values in the 1D array

	for (int i = 0; i < n; i++) {
		cin >> ptr[i]; // cin >> *(ptr+i);
	}

	// print values of the 1D array

	for (int i = 0; i < n; i++) {
		cout << ptr[i] << " " << *(ptr + i) << endl;
	}

	// deallocate memory for 1D array

	delete [] ptr;

	return 0;
}