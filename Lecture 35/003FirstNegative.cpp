#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window

	queue<int>  q; // to store negative numbers in a window
	vector<int> ans; // to store first negative number for each k-sized window

	// time : O(n)
	// space: O(k) due to queue when window has all -ve elements

	// find the first negative number in the 1st window

	while (j < k) {
		if (arr[j] < 0) {
			q.push(arr[j]);
		}
		j++;
	}

	if (q.empty()) {
		// current window has no negative elements
		ans.push_back(0);
	} else {
		ans.push_back(q.front());
	}

	// find the first negative number in the remaining windows

	while (j < n) {

		// slide the window

		if (arr[i] < 0) { // element being removed from the window is negative so remove it from queue
			q.pop();
		}
		i++;
		if (arr[j] < 0) { // element being added to the window is negative so track it in queue
			q.push(arr[j]);
		}

		// update the ans for the current window

		if (q.empty()) {
			// current window has no negative elements
			ans.push_back(0);
		} else {
			ans.push_back(q.front());
		}

		// continue the same process

		j++;

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}

