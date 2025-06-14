/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s; // s is a set of integers maintained in inc. order
	// set<int, greater<int>> s; // is a set of integers maintained in dec. order

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // ignored since set<> contains distinct elements

	cout << "size : " << s.size() << endl; // 5

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(5); // since 5 is present in the set<>, it will be erased

	cout << "size : " << s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	// set<> doesn't support indexing

	s.erase(s.begin()); // erases the 1st element of the set<>

	cout << "size : " << s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	auto it = s.begin();
	it++;
	s.erase(it);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.find(4) != s.end()) {
		cout << "4 is present" << endl;
	} else {
		cout << "4 is absent" << endl;
	}

	if (s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}

	if (s.count(2)) {
		cout << "2 is present" << endl;
	} else {
		cout << "2 is absent" << endl;
	}

	s.empty() ? cout << "set<> is empty" << endl : cout << "set<> is non-empty" << endl;

	s.clear();

	cout << "size : " << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl : cout << "set<> is non-empty" << endl;

	return 0;
}