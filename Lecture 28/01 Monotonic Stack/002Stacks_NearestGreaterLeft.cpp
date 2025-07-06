#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(vector<int>& A) { // here, A[] is passed by ref to avoid copy which is expensive op for vector<>

	int n = A.size();
	stack<int> s; // monotonic stack
	vector<int> ans; // to track the nearest greater element to the left of each element in A[]

	for (int i = 0; i < n; i++) {

		// find the nearest greater element to the left
		// of A[i] using the monotonic stack

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the left of A[i]
			ans.push_back(-1);
		} else {
			// s.top() is the nearest greater element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 2, 0, 4, 1, 3, 6};

	vector<int> ans = f(A);

	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}