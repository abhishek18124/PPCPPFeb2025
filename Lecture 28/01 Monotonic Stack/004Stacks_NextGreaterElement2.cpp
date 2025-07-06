#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n)

vector<int> f(vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<pair<int, int>> s; // monotonic stack // <value, index>

	for (int i = 0; i < n; i++) {

		// what are the elements for which A[i] is the ans i.e. A[i]
		// is the nearest greater element

		while (!s.empty() and A[i] > s.top().first) {
			// A[i] is the ans for s.top().first
			ans[s.top().second] = A[i];
			s.pop();
		}

		s.push({A[i], i});

	}

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f(A);

	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}