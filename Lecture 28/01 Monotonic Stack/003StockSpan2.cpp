#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(vector<int>& A) {

	stack<int> s; // monotonic stack // <index>
	vector<int> span;

	for (int i = 0; i < A.size(); i++) {

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// there is no greater element to the left A[i]
			j = -1;
		} else {
			// s.top().first is the nearest greater element to the left of A[i]
			j = s.top();
		}

		span.push_back(i - j);
		s.push(i);

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