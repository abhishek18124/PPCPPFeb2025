/*

optimising union and find operations using

* union by rank
* path compression

*/

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> parMap;
	vector<int> sizeMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		sizeMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		sizeMap[x] = 1;
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

			if (sizeMap[lx] > sizeMap[ly]) {
				parMap[ly] = lx;
				sizeMap[lx] += sizeMap[ly];
			} else {
				parMap[lx] = ly;
				sizeMap[ly] += sizeMap[lx];
			}

		}

	}

};


int main() {

	int n;
	cin >> n;

	disjointSet ds(n);

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(2, 3);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;


	return 0;

}