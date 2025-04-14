/*

e.g.

input
5 3
4 1 5 2 3
0 2 5
2 3 2
3 4 7

output
9 6 12 11 10

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> diff(n + 1, 0);
	while (q--) { // q steps and each step is const
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}

	for (int i = 1; i <= n; i++) { // n steps and each step is const
		diff[i] = diff[i] + diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 0; i < n; i++) { // n steps and each step is const
		v[i] += diff[i];
	}

	// total steps = q + n + n = 2n + q.const ~ O(n+q)

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}