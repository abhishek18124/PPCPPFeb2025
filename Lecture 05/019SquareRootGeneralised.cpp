#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	// find out the square root n upto p places

	double ans = 0; // to store the square root of n

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	int i = 1;
	double inc = 0.1;

	while (i <= p) {
		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;
		i = i + 1;
	}

	cout << ans;

	return 0;
}