// https://leetcode.com/problems/max-area-of-island/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	int dfs(int i, int j,
	        const vector < vector<int>>& grid,
	        vector<vector<bool>>& vis, int m, int n) {

		vis[i][j] = true;

		// return the size of the component of node corr. to the (i, j)th cell

		int cnt = 1; // to track the size of the component of node corr. to the (i, j)th cell

		int nx = i;
		int ny = j + 1;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		        grid[nx][ny] == 1 and
		        !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i;
		ny = j - 1;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		        grid[nx][ny] == 1 and
		        !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i - 1;
		ny = j;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		        grid[nx][ny] == 1 and
		        !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i + 1;
		ny = j;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		        grid[nx][ny] == 1 and
		        !vis[nx][ny]) {
			cnt += dfs(nx, ny, grid, vis, m, n);
		}

		return cnt;

	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<bool>> vis(m, vector<bool>(n, false));
		int maxsofar = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {
					maxsofar = max(maxsofar, dfs(i, j, grid, vis, m, n));
				}
			}
		}

		return maxsofar;

	}
};

int main() {

	vector<vector<int>> grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	Solution s;

	cout << s.maxAreaOfIsland(grid) << endl;

	return 0;

}