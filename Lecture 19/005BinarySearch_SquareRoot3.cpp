#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int n;
	cin >> n;

	double ans;

	double s = 0;
	double e = n;

	double moe = 1e-16; // margin of error allowed

	while (e - s > moe) {

		cout << ".";

		double m = s + (e - s) / 2;

		// can 'm' be the square root of 'n' ?

		if (m * m <= n) {

			ans = m;
			s = m + moe;

		} else {

			e = m - moe;

		}

	}

	cout << setprecision(6) << fixed << ans << endl;

	return 0;
}