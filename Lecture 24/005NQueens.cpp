// https://leetcode.com/problems/n-queens/description/

class Solution {

public:

	bool isValid(int n, vector<string>& board, int r, int j) { // [HW] try to optimise

		// check if we can place Qr in the jth column of row r

		// 1. check if there is any previously placed queen (Q0...Qr-1) in the jth column

		for (int i = 0; i <= r - 1; i++) {
			if (board[i][j] == 'Q') {
				// there is already a previosly placed queen in the jth column therefore
				// you cannot place Qr in the jth column of row r
				return false;
			}
		}

		// 2. check if there is any previously placed queen (Q0...Qr-1) in the right diagonal of jth column

		int step = 1;
		for (int i = r - 1; i >= 0 and j + step < n; i--) { // here, it is imp. to iterate from r-1 to 0
			if (board[i][j + step] == 'Q') {
				return false;
			}
			step++;
		}

		// 3. check if there is any previously placed queen (Q0...Qr-1) in the left diagonal of the jth column

		step = 1;
		for (int i = r - 1; i >= 0 and j - step >= 0; i--) { // here, it is imp. to iterate from r-1 to 0
			if (board[i][j - step] == 'Q') {
				return false;
			}
			step++;
		}

		return true;

	}

	void f(int n, int r, vector<string>& board, vector<vector<string>>& ans) {

		// base case

		if (r == n) { // all the n queens are placed i.e. we've build a valid config
			ans.push_back(board); // track the valid config in ans
			return;
		}

		// recursive case

		// f(r) = make decisions for remaining queens from Qr to Qn-1

		// decide for Qr

		for (int j = 0; j < n; j++) {

			// can I place Qr in the jth column of row r ?

			if (isValid(n, board, r, j)) {
				// yes, you can place Qr in the jth column of row r
				board[r][j] = 'Q';
				f(n, r + 1, board, ans);
				board[r][j] = '.'; // backtracking
			}

		}

	}

	vector<vector<string>> solveNQueens(int n) {

		vector<string> board; // board is a collection of strings and stores a valid config
		for (int i = 0; i < n; i++) {
			string row(n, '.'); // each row is a string of size n filled with '.'
			board.push_back(row);
		}

		vector<vector<string>> ans; // to track all the valid configs

		f(n, 0, board, ans);

		return ans;

	}
};