#include<iostream>
#include<vector>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : n for r[] + n for total ~ O(n)
	// space: n for r[] = n ~ O(n)

	vector<int> r(n);
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int li = 0;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building i.e. wi

		li = max(li, h[i]);
		int wi = min(li, r[i]) - h[i];
		total += wi;

	}

	cout << total << endl;


	return 0;
}