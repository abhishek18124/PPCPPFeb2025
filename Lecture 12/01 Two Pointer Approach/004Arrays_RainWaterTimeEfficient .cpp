#include<iostream>
#include<vector>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	vector<int> l(n);
	l[0] = h[0];
	for (int i = 1; i <= n - 1; i++) {
		l[i] = max(l[i - 1], h[i]);
	}

	vector<int> r(n);
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building i.e. wi

		int wi = min(l[i], r[i]) - h[i];
		total += wi;

	}

	cout << total << endl;


	return 0;
}