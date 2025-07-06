#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to the monotonic stack

vector<int> f(vector<int>& A) { // here, A[] is passed by ref to avoid copy which is expensive op for vector<>

	int n = A.size();
	stack<int> s; // monotonic stack
	vector<int> ans; // to track the nearest greater element to the right of each element in A[]

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right
		// of A[i] using the monotonic stack

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the right of A[i]
			ans.push_back(-1);
		} else {
			// s.top() is the nearest greater element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};
	int n = A.size();

	vector<int> ans = f(A);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}