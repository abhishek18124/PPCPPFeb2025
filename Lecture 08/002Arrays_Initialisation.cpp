#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50}; // specifying size of the arr[] during initialisation is optional
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// int B[5] = {1, 2, 3, 4, 5, 6}; // error

	int C[5] = {100, 200, 300};
	for (int i = 0; i < 5; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int arr[10] = {};
	int brr[10] = {0};

	int crr[10];
	memset(crr, 0, sizeof(crr));

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < 10; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < 10; i++) {
		cout << crr[i] << " ";
	}

	cout << endl;

	int drr[10];
	memset(drr, 2, sizeof(drr));

	for (int i = 0; i < 10; i++) {
		cout << drr[i] << " ";
	}

	cout << endl;


	return 0;
}