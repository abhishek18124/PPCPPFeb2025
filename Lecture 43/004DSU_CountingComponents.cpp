/*

counting no. of componenets in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 7

1 2
1 4
2 3
3 4
5 6
6 7

output :

2

*/

#include<iostream>
#include<vector>

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
	int u, v;
	edge(int u, int v) {
		this->u = u;
		this->v = v;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back(edge(u, v));
	}

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	int numComponents = n;

	for (edge e : edges) {
		int u = e.u;
		int v = e.v;
		if (ds.findSet(u) != ds.findSet(v)) {
			ds.unionSet(u, v);
			numComponents--;
		}
	}

	cout << numComponents << endl;

	return 0;
}