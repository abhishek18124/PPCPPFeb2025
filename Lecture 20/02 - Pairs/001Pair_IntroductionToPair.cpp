/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members first and second.
*/

#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main() {

	pair<int, int> p;

	p.first = 10;
	p.second = 20;

	cout << p.first << " " << p.second << endl;

	pair<string, int> p2 = {"Opertion Sindoor", 11};

	cout << p2.first << " " << p2.second << endl;

	pair<char, int> p3 = make_pair('A', 1);

	cout << p3.first << " " << p3.second << endl;

	vector<pair<int, int>> v;

	v.push_back({3, 4});
	v.push_back({2, 5});
	v.push_back({6, 9});
	v.push_back({5, 1});
	v.push_back({6, 2});

	for (pair<int, int> p : v) {
		cout << p.first << " " << p.second << endl;
	}


	cout << endl;

	sort(v.begin(), v.end()); // vector<pair<>> is by default sorted in inc. order on the 1st member of pair, and if the first member matches then sorting is done on 2nd member

	for (pair<int, int> p : v) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}