#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m; // n represents no. of nodes // m represents no. of edges
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v; // u & v are used to store edge info.
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") = ";
		vector<int> ngblist = adj[i];
		for (int ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") = ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}