#include<iostream>

using namespace std;

// time : O(n^2)

int targetSumPairs(int arr[], int n, int t) {

	int cnt = 0;

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int pairSum = arr[i] + arr[j];
			if (pairSum == t) {
				cnt++;
			}
		}
	}

	return cnt;

}

// time : O(n)

int targetSumPairsOptimised(int arr[], int n, int t) {
	int i = 0;
	int j = n - 1;
	int cnt = 0;
	while (i < j) {
		int pairSum = arr[i] + arr[j];
		if (pairSum == t) {
			cnt++;
			i++;
			j--;
		} else if (pairSum < t) {
			i++;
		} else {
			j--;
		}
	}

	return cnt;
}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	cout << targetSumPairs(arr, n, t) << endl;

	cout << targetSumPairsOptimised(arr, n, t) << endl;

	return 0;
}