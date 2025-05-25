// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int j = s;
	int i = s - 1;

	while (j < e) {

		if (arr[j] < pivot) {

			// put arr[j] in left part
			i++;
			swap(arr[i], arr[j]);
			j++;

		} else {

			// put arr[j] in right part
			j++;

		}

	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s == e) { // optional
		return;
	}

	if (s > e) { // mandatory
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot

	int pidx = partition(arr, s, e);

	// 2. ask your friend to quick sort left and right partition i.e. arr[s...pidx-1] and arr[pidx+1...e]

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}