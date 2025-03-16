#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {
		cout << n << endl; // since 0th fib. no. is 0 and 1st fib. no. is 1
	} else {
		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.
		// int c;

		// no. of iterations = n-1
		// time spent in each iteration = const i.e. independent of i/p size
		// total time = n-1.c ~ n.c ~ O(n)

		int i = 1;

		while (i <= n - 1) {
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		// cout << c << endl;
		cout << b << endl;

	}

	return 0;
}