#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. sorting a sequence using built-in sort() in O(nlogn) // introsort used

	sort(arr, arr + n); // sorts arr[0, n) i.e. from idx 0 to n-1

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int brr[] = {20, 30, 50, 10, 40};
	sort(brr + 1, brr + 4); // sorts brr[1,4) i.e. from idx 1 to 3
	for (int i = 0; i < 5; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	// 2. reversing a sequence using the built-in reverse()

	reverse(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 3. reversing a sequence in-range using the built-in reverse()

	reverse(brr + 1, brr + 4);
	for (int i = 0; i < 5; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	// reverse(arr+i, arr+j) // [i, j)
	// sort(arr+i, arr+j) // [i, j)

	return 0;
}
