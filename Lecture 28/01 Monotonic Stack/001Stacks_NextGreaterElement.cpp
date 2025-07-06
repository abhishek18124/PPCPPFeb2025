#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};
	int n = A.size();

	vector<int> ans(n, -1);

	// time : O(n)

	for (int i = 0; i < n; i++) {

		// find the nearest greater element to the right of A[i]

		for (int j = i + 1; j < n; j++) {

			if (A[j] > A[i]) {

				// A[j] is the nearest greater element for A[i]

				ans[i] = A[j];

				break;

			}

		}

	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}