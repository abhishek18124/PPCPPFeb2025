#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freq[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch, as of now, is non-repeating char therefore track it
			q.push(ch);
		}

		// find the 1st non-repeating char. in the stream after reading ch

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			// char at q.front() is no longer non-repeating char
			q.pop();
		}

		if (q.empty()) {
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}