#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;
	int rtn = sqrt(n); // implicit type-casting is happening here

	while (i <= rtn) {

		if (n % i == 0) {
			// you've found a factor of n in the range [2, n-1] therefore
			cout << "not prime" << endl;
			break;
		}

		i = i + 1;

	}

	if (i > rtn) { // you've scanned the entire range
		// [2, rtn] and you did not find any factor
		// of n therefore
		cout << "prime" << endl;
	}

	return 0;
}