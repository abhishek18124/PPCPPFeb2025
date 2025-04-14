/*

https://codeforces.com/problemset/problem/276/C

e.g.

input
3 3
5 3 2
1 2
2 3
1 3

output
25

input
5 3
5 2 4 1 3
1 5
2 3
2 3

output
33

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> diff(n + 1, 0);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		diff[l] += 1;
		diff[r + 1] -= 1;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// greedily map frequencies with array elements

	sort(v.begin(), v.end());
	sort(diff.begin(), diff.end() - 1); // -1 cuz we don't to incl last slot in sorting

	long long ans = 0; // long long to avoid overflow
	for (int i = 0; i < n; i++) {
		ans += (long long)v[i] * diff[i];
	}

	cout << ans << endl;

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	return 0;
}