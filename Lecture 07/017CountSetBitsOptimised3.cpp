#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int cnt = 0; // to track the no. of set bits in 'n'

	// #iterations = #set bits in n

	while (n > 0) {
		// clear the rightmost set bit of n
		n = n & (n - 1);
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}