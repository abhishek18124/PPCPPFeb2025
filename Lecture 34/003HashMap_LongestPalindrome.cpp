#include<iostream>
#include<vector>
#include<set>

using namespace std;

// time : O(n.log(size of set)) // size of set<> will not exceed 52
// space: O(size of set)

int lengthOflongestPalindrome(const string& str) {

	set<char> s;
	int ans = 0;

	for (char ch : str) {
		if (s.find(ch) == s.end()) {
			// you've not seen ch previously
			s.insert(ch);
		} else {
			ans += 2;
			s.erase(ch);
		}
	}

	if (!s.empty()) {
		ans++;
	}

	return ans;

}

int main() {

	string str = "abccccdd";

	cout << lengthOflongestPalindrome(str) << endl;

	return 0;
}