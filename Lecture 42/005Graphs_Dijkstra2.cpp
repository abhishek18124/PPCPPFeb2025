/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int src = 0; // assume node 0 to be the src vertex

	vector<bool> ex(n, false); // ex[i] stores the info. if node i is explored or not

	vector<int> distMap(n, INF);
	distMap[src] = 0;

	set<pair<int, int>> minHeap;
	minHeap.insert({distMap[src], src});

	// time : O(ElogV) // in the worst case, you'll relax each edge exactly once
	// space: O(V)

	while (!minHeap.empty()) {

		pair<int, int> p = *minHeap.begin();
		minHeap.erase(minHeap.begin());
		int dis_cur = p.first;
		int cur = p.second;

		// auto [dis_cur, cur] = *minHeap.begin(); // works C++17 onwards
		// minHeap.erase(minHeap.begin());

		// for(pair<int ,int> p : adj[cur]) {
		// 	int ngb = p.first;
		// 	int edgeWgt = p.second;
		// 	...
		// }

		for (auto [ngb, edgeWgt] : adj[cur]) {

			if (!ex[ngb] and distMap[ngb] > dis_cur + edgeWgt) {
				// edge b/w cur and ngb is tensed so relax that edge
				minHeap.erase({distMap[ngb], ngb});
				distMap[ngb] = dis_cur + edgeWgt;
				minHeap.insert({distMap[ngb], ngb});
			}

		}

		ex[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << distMap[i] << endl;
	}

	cout << endl;

	return 0;
}