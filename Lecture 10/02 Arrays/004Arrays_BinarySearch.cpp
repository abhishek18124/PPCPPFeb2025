#include<iostream>

using namespace std;

// time : O(logn)

int binarySearch(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {
		// int m = (s + e) / 2;
		int m = s + (e - s) / 2;
		if (arr[m] == t) {
			// you've found the 't' at index 'm'
			return m;
		} else if (t > arr[m]) {
			// binary search 't' in [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// binary search 't' in [s, m-1]
			e = m - 1;
		}
	}

	// t not found since search space is now empty i.e. s > e
	return -1;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	cout << binarySearch(arr, n, t) << endl;

	return 0;
}