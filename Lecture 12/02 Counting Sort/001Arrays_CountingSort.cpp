/*

e.g.

input
9
1 0 3 2 3 1 2 0 2
3

output
0 0 1 1 2 2 2 3 3

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 1. build a freqMap // n-steps

	vector<int> freq(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int x = v[i];
		freq[x]++;
	}

	for (int i = 0; i <= k; i++) {
		cout << "freq(" << i << ") = " << freq[i] << endl;
	}

	// 2. use freqMap to print sorted array // n-steps

	for (int i = 0; i <= k; i++) {

		// print i freq[i] times

		for (int j = 1; j <= freq[i]; j++) {
			cout << i << " ";
		}

	}

	cout << endl;

	// total time : n + n = 2n.const ~ O(n)
	// space : k+1 due to freq[] ~ O(k)

	return 0;
}


