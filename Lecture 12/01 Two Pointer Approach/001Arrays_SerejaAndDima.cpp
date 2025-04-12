#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int i = 0;
	int j = n - 1;

	int serejaScore = 0;
	int dimaScore = 0;

	bool serejaTurn = true;

	while (i <= j) {

		if (serejaTurn) {

			// it is sereja's turn

			if (v[i] > v[j]) {

				// sereja will pick the ith card

				serejaScore += v[i];
				i++;

			} else {

				// sereja will pick the jth card

				serejaScore += v[j];
				j--;

			}

			serejaTurn = false;

		} else {

			// it is dima's turn

			if (v[i] > v[j]) {

				// dima will pick ith card

				dimaScore += v[i];
				i++;

			} else {

				// dima will pick jth card

				dimaScore += v[j];
				j--;

			}

			serejaTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}