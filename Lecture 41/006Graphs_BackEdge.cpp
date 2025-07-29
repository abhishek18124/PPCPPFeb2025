/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& inStk) {

	vis[cur] = true;
	inStk[cur] = true; // cur node is present on the fn call stack

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			if (dfs(ngb, adj, vis, inStk)) {
				// you've found a backedge in the subcomponent of ngb
				// i.e. you've found a backedge in the component of
				// cur
				return true;
			}
		} else {
			// ngb is already visited
			// check if cur to ngb directed edge is a backedge ?
			// check if there is directed path from ngb to cur ?
			// check if ngb is present on the fn call stack while we are at cur
			if (inStk[ngb]) {
				// ngb is present on the function call stack
				// therefore there is directed path from ngb
				// to cur therefore cur to ngb is backedge
				return true;
			}
		}
	}

	// no backedge found in the cur component
	inStk[cur] = false;
	return false;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // graph is directed
	}

	vector<bool> vis(n, false);
	vector<bool> inStk(n, false);

	bool flag = false; // assume there is no backedge i.e. directed cycle in the graph

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			// use dfs to check if the component of node i
			// contains a backedge or not i.e. check if the
			// component of node i contains a directed cycle
			if (dfs(i, adj, vis, inStk)) {
				// you've found a backedge in the component of node i
				// i.e. you've found a directed cycle in the given
				// graph
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << "directed cycle found" << endl;
	} else {
		cout << "no directed cycle found" << endl;
	}

	return 0;

}