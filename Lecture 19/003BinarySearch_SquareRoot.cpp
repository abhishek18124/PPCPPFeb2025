#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans;

	int s = 0;
	int e = n;

	while (s <= e) {

		int m = s + (e - s) / 2;

		// can 'm' be the square root of 'n' ?

		if (m * m <= n) {

			ans = m;
			s = m + 1;

		} else {

			e = m - 1;

		}

	}

	double inc = 0.1;

	for (int i = 1; i <= p; i++) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;

	}

	cout << ans << endl;

	// time : logn + p.10 ~ O(logn)

	return 0;
}