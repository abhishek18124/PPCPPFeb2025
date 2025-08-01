#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> parMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
	}

	int findSet(int x) {

		// base case
		if (parMap[x] == x) {
			return x;
		}

		// recursive case
		return findSet(parMap[x]);

	}

	void unionSet(int x, int y) {

		int lx = findSet(x);
		int ly = findSet(y);
		if (lx != ly) {
			parMap[lx] = ly; // make ly parent of lx
			// parMap[ly] = lx // or make lx parent of ly
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