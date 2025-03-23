#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {
		int rightmostbit = n & 1;
		if (rightmostbit) {
			cnt++;
		}
		n = n >> 1;
	}

	cout << cnt << endl;
	return 0;
}