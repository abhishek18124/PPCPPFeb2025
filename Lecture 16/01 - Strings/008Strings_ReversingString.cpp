#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abcd";

	reverse(s.begin(), s.end());

	cout << s << endl;

	string t = "coding";

	// reverse t from index 1 to index 3

	reverse(t.begin() + 1, t.begin() + 4); // [1, 4)

	cout << t << endl;

	return 0;
}