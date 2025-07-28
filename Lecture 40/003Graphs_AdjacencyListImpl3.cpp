#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<string, vector<string>> adj; // use map<string, set<string>> if you want ngblist to be sorted
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	for (pair<string, vector<string>> p : adj) {
		string nodeLabel = p.first;
		vector<string> ngblist = p.second;
		cout << "ngb(" << nodeLabel << ") = ";
		for (string ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [nodeLabel, ngblist] : adj) {
		cout << "ngb(" << nodeLabel << ") = ";
		for (string ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}