/*

Given an undirected graph, check if it is bipartite or not ?

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, int color, const vector<vector<int>>& adj,
         vector<int>& colorMap) {

	colorMap[cur] = color;

	for (int ngb : adj[cur]) {
		if (colorMap[ngb] == -1) {
			// ngb is not yet colored i.e. it is not yet visited
			if (dfs(ngb, 1 - color, adj, colorMap) == false) {
				// subcomponent of ngb is not bipartite
				// which means component of cur is not
				// biparitite
				return false;
			}
		} else {
			// ngb is already colored
			if (colorMap[ngb] == colorMap[cur]) {
				// component of cur is not bipartite
				return false;
			}
		}
	}

	// component of cur is bipartite
	return true;

}


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	// color red - 0
	// color green - 1

	vector<int> colorMap(n, -1); // -1 means no node is colored
	bool flag = true; // assume graph is bipartite

	for (int i = 0; i < n; i++) {

		if (colorMap[i] == -1) {

			// use dfs to check if the component of
			// node i is bipartite or not

			if (dfs(i, 0, adj, colorMap) == false) { // assume node i is given color 0
				// component of node i is not bipartite
				// therefore given graph is not bipartite
				flag = false;
				break;
			}

		}

	}

	if (flag) {
		cout << "graph is bipartite" << endl;
	} else {
		cout << "graph is not bipartite" << endl;
	}


	return 0;
}