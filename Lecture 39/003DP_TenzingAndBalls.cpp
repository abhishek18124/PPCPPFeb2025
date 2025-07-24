/*

https://codeforces.com/problemset/problem/1842/C

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(int n, vector<int>& a, int i) {

	// base case

	if (i == n) {
		// f(n) = find the max. no. of balls tenzing
		// can remove from a[n...n-1] = {}
		return 0;
	}

	// recursive case

	// f(i) = find the max. no. of balls tenzing
	// can remove from a[i...n-1]

	// decide for the ith ball

	// option 1 : don't remove the ith ball

	int donotRemoveOption = f(n, a, i + 1);

	// option 2 : remove the ith ball

	int removeOptionMaxSoFar = INT_MIN;
	for (int j = i + 1; j < n; j++) {
		if (a[j] == a[i]) {
			removeOptionMaxSoFar = max(removeOptionMaxSoFar, (j - i + 1) + f(n, a, j + 1));
		}
	}

	return max(donotRemoveOption, removeOptionMaxSoFar);

}

// time : O(n^2)
// space: O(n) due to dp[]

int fBottomUp(int n, vector<int>& a) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[] we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i) = find the max. no. of balls tenzing can remove from a[i...n-1]

		// decide for the ith ball

		// option 1 : don't remove the ith ball

		int donotRemoveOption = dp[i + 1];

		// option 2 : remove the ith ball

		int removeOptionMaxSoFar = INT_MIN;

		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				removeOptionMaxSoFar = max(removeOptionMaxSoFar, (j - i + 1) + dp[j + 1]);
			}
		}

		dp[i] = max(donotRemoveOption, removeOptionMaxSoFar);

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		// cout << f(n, a, 0) << endl;
		cout << fBottomUp(n, a) << endl;

	}

	return 0;
}
