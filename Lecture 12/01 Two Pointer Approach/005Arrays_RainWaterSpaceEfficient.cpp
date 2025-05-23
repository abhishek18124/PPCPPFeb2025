#include<iostream>

using namespace std;

int main() {

	// time : O(n)
	// space: O(1)

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int i = 0;
	int j = n - 1;

	int total = 0;

	int l = 0; // max(0 to i)
	int r = 0; // max(j to n-1)

	while (i <= j) {

		l = max(l, h[i]); // max(0 to i)
		r = max(r, h[j]); // max(j to n-1)

		if (l < r) {

			int wi = l - h[i];
			total += wi;
			i++;

		} else {

			int wj = r - h[j];
			total += wj;
			j--;

		}

	}

	cout << total << endl;

	return 0;
}