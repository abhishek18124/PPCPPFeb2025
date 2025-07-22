/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {
		return 1 + f(s1, s2, m, n, i + 1, j + 1);
	} else {
		return max(f(s1, s2, m, n, i, j + 1),
		           f(s1, s2, m, n, i + 1, j));
	}

}

// time : O(mn)
// space: O(mn) due to dp[][]

int fBottomUp(string& s1, string& s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// 0 init of dp[][] handles the base case cells

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {

			// dp[i][j] = f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]
			if (s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return dp[0][0]; // at the 0,0th index of dp[][]
	// we store f(0, 0)

}

// time : O(mn)
// space: O(n) due to cur[] and nxt[]
// [HW] try to solve this question using only 1 1d vector

int fBottomUpSpaceOptimised(const string& s1, const string& s2, int m, int n) {

	vector<int> nxt(n + 1, 0); // init it represents the mth row of dp[][]

	for (int i = m - 1; i >= 0; i--) {

		vector<int> cur(n + 1); // to store the values of the ith row
		cur[n] = 0; // nth cell of each row is 0 as it corresponds to the base case

		for (int j = n - 1; j >= 0; j--) {

			if (s1[i] == s2[j]) {
				cur[j] = 1 + nxt[j + 1]; // nxt[j+1] means dp[i+1][j+1]
			} else {
				cur[j] = max(cur[j + 1], nxt[j]); // cur[j+1] means dp[i][j+1], nxt[j] means dp[i+1][j]
			}

		}

		nxt = cur; // make cur row as the nxt row before the next iteration

	}

	return nxt[0]; // nxt[0] represents dp[0][0]

}

int main() {

	string s1("ATGC");
	string s2("ACTG");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	cout << fBottomUpSpaceOptimised(s1, s2, m, n) << endl;

	return 0;
}