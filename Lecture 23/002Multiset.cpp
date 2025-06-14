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

	multiset<int> s; // s is a multiset of integers maintained in inc. order
	// multiset<int, greater<int>> s; // is a multiset of integers maintained in dec. order

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1);

	cout << "size : " << s.size() << endl; // 5

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	cout << s.count(1) << endl;

	return 0;
}