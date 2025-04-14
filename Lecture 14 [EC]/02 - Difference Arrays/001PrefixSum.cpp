#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	/*

	find out prefix sums and store them in arr[] itself

	sum(10) = 10
	sum(10 20) = 30
	sum(10 20 30) = 60
	sum(10 20 30 40) = 100
	sum(10 20 30 40 50) = 150

	*/

	for (int i = 1; i < n; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}