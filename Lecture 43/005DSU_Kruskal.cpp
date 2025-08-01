/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class disjointSet {

	vector<int> parMap;
	vector<int> rankMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {

		// base case
		if (parMap[x] == x) {
			return x;
		}

		// recursive case
		return parMap[x] = findSet(parMap[x]); // path compression

	}

	void unionSet(int x, int y) { // union by rank

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				parMap[lx] = ly;
			}

		}

	}

};


class edge {
public:
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool cmp(edge a, edge b) {
	if (a.w < b.w) {
		// we are sorting edges in inc. order based on wgt
		// so if weight of edge a is less than weight of
		// edge b we want a to come before b
		return true;
	}
	return false;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
	}

	sort(edges.begin(), edges.end(), cmp); // ElogE

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) { // V.const
		ds.createSet(i);
	}

	int mstSum = 0; // to track sum of mst
	vector<edge> mst; // to track safe edges we've picked

	for (edge e : edges) { // E.const
		int u = e.u;
		int v = e.v;
		int w = e.w;
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge, so pick it
			mst.push_back(e);
			mstSum += w;
			ds.unionSet(u, v);
			if (mst.size() == n - 1) break; // we've built the mst, no need to iterate over remaining edges
		}
	}

	for (edge e : mst) {
		int u = e.u;
		int v = e.v;
		int w = e.w;
		cout << u << " " << v << " : " << w << endl;
	}

	cout << mstSum << endl;

	// time : ElogE + V + E ~ O(ElogE)
	// space: O(V) due to disjointSet

	return 0;
}