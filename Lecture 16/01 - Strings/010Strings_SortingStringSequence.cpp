#include<iostream>
#include<vector>
#include<string>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool cmp(string a, string b) {

	// if (a.size() < b.size()) {
	// 	// we want a to be ordered before b
	// 	// since we are sorting length-wise
	// 	// in inc. order

	// 	return true;
	// }

	// return false;

	return a.size() < b.size();

}

int main() {

	vector<string> v;

	v.push_back("khushi");
	v.push_back("dhruv");
	v.push_back("om");
	v.push_back("riya");
	v.push_back("ram");

	// sort(v.begin(), v.end()); // sort vec<> in lexicographically inc. order
	// sort(v.rbegin(), v.rend()); // sort vec<> in lexicographically dec. order
	// sort(v.begin(), v.end(), greater<string>()); // sort vec<> in lexicographically dec. order

	sort(v.begin(), v.end(), cmp);
	// sort(v.begin(), v.end(), &cmp); // & is optional to extract addr of fn

	for (string s : v) {
		cout << s << endl;
	}

	cout << endl;

	return 0;
}