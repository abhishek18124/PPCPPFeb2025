#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(vector<int>& A) {

	stack<pair<int, int>> s; // monotonic stack // <value, index>
	vector<int> span;

	for (int i = 0; i < A.size(); i++) {

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and s.top().first <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the left A[i]
			j = -1;
		} else {
			// s.top().first is the nearest greater element to the left of A[i]
			j = s.top().second;
		}

		span.push_back(i - j);
		s.push({A[i], i}); // s.push(make_pair(A[i], i));

	}

	return span;

}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85};

	vector<int> span = f(A);

	for (int x : span) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}