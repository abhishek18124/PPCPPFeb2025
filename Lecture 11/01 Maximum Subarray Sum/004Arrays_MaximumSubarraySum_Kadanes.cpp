// constraints : n <= 100

#include<iostream>

using namespace std;

// time : O(n)
// space: O(n) due x[]

int maximumSubarraySumUsingKadanes(int arr[], int n) {

	int x[100]; // based on constraints
	x[0] = arr[0];

	int maxSofar = x[0];

	for (int i = 1; i <= n - 1; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]);
		maxSofar = max(maxSofar, x[i]);
	}

	return maxSofar;

}

// time : O(n)
// space: O(1)

int maximumSubarraySumUsingKadanesSpaceOptimised(int arr[], int n) {

	int x = arr[0];
	int maxSofar = x;

	for (int i = 1; i <= n - 1; i++) {
		x = max(x + arr[i], arr[i]);
		maxSofar = max(maxSofar, x);
	}

	return maxSofar;

}


int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumUsingKadanes(arr, n) << endl;

	cout << maximumSubarraySumUsingKadanesSpaceOptimised(arr, n) << endl;

	return 0;
}