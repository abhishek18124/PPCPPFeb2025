#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;

	while (i <= n) {

		// for the ith row, print i nos.

		// int num;
		// if (i % 2 == 0) {
		// 	// we are in an even row
		// 	num = 0;
		// } else {
		// 	// we are in an odd row
		// 	num = 1;
		// }

		int num = i % 2 == 0 ? 0 : 1;

		int j = 1;
		while (j <= i) {
			cout << num << " ";
			num = 1 - num; // this stmt. flips the num

			// num = !num;

			// if (num == 0) {
			// 	num = 1;
			// } else {
			// 	num = 0;
			// }

			j++;
		}

		cout << endl;
		i++;

	}

	return 0;
}