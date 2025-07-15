#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn)
// space: O(n) due map<> when each element in the array is distinct

bool isDuplicatePresent(const vector<int>& v) {

	map<int, int> freqMap;

	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1)  {
			// you've found a duplicate
			return true;
		}
	}

	// there are no duplicates found

	return false;

	// for (pair<int, int> p : freqMap) {
	// 	int el = p.first;
	// 	int fr = p.second;
	// 	cout << el << " : " << fr << endl;
	// }

	// cout << endl;

	// for (auto [el, fr] : freqMap) { // c++17
	// 	cout << el << " : " << fr << endl;
	// }


}

// time : O(nlogn)
// space: O(n) due to set<>

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s;

	for (int x : v) {
		if (s.find(x) == s.end()) {
			// you've not seen x previously
			s.insert(x);
		} else {
			// you've seen x previously, i.e. duplicate found
			return true;
		}
	}

	return false; // no duplicates found

}


int main() {

	vector<int> v = {1, 2, 3, 4, 5};

	isDuplicatePresent(v) ? cout << "duplicate found" << endl :
	                             cout << "no duplicate found" << endl;


	isDuplicatePresentUsingSet(v) ? cout << "duplicate found" << endl :
	                                     cout << "no duplicate found" << endl;

	return 0;
}