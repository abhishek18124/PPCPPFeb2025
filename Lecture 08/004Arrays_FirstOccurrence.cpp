#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i;

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			// we've found 1st occ of the 't' at index i
			cout << i << endl;
			break;
		}
	}

	if (i == n) {
		cout << -1 << endl;
	}

	return 0;
}