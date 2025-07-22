/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>

using namespace std;

// time : O(2^n)
// space: O(n) due to function call stack

int f(const vector<int>& p, int i, int j, int y) {

	// base case

	if (i == j) { // you are left with a single bottle of wine
		return p[i] * y; // p[j] * y // here y will equal to n
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

// time : O(n^3)
// space: n due to fn call stack + n^3 due to dp[][][] ~ O(n^3)

int fTopDown(const vector<int>& p, int i, int j, int y, vvvi& dp) {

	// lookup
	if (dp[i][j][y] != -1) {
		// you've solved f(i, j, y) previously so reuse the result
		return dp[i][j][y];
	}

	// base case

	if (i == j) { // you are left with a single bottle of wine
		return dp[i][j][y] = p[i] * y; // p[j] * y // here y will equal to n
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return dp[i][j][y] = max(y * p[i] + fTopDown(p, i + 1, j, y + 1, dp),
	                         y * p[j] + fTopDown(p, i, j - 1, y + 1, dp));

}

// time : O(n^2)
// space: O(n^2)

int fTopDownStateOptimised(vector<int>& p, int i, int j, vvi& dp) {

	int y = p.size() - j + i;

	// lookup
	if (dp[i][j] != -1) {
		// you've solved f(i, j) previously so reuse the result
		return dp[i][j];
	}

	// base case

	if (i == j) { // you are left with a single bottle of wine
		return dp[i][j] = p[i] * y; // p[j] * y // here y will equal to n
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle

	// option 2 : sell the jth bottle

	return dp[i][j] = max(y * p[i] + fTopDownStateOptimised(p, i + 1, j, dp),
	                      y * p[j] + fTopDownStateOptimised(p, i, j - 1, dp));

}

// time : (n^2/2).const ~ O(n^2)
// space: O(n^2)

int fBottomUp(vector<int>& p, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		int j = i;
		int y = n;
		dp[i][j] = y * p[i]; // y * p[j]
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			int y = n - j + i;
			// dp[i][j] = f(i, j) = max. profit from bottles i to j
			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);
		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index of dp[][] we store f(0, n-1)

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	// cout << f(p, 0, n - 1, 1) << endl;

	// vvvi dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

	// cout << fTopDown(p, 0, n - 1, 1, dp) << endl;

	vvi dp(n, vector<int>(n, -1));

	cout << fTopDownStateOptimised(p, 0, n - 1, dp) << endl;

	cout << fBottomUp(p, n) << endl;

	return 0;
}