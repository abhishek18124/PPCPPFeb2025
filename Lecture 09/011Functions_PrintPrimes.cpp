#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int squareRootN = sqrt(n);

	for (int i = 2; i <= squareRootN; i++) {
		if (n % i == 0) {
			// you've found a factor of n in the range [2, n-1]
			// therefore n is a composite no.
			return false;
		}
	}

	return true; // n is a prime number

}

// 3 adv. of using fn

// 1. reusability
// 2. modularity
// 3. readability


void printPrimes(int m) {
	for (int n = 2; n <= m; n++) {
		// check if n is prime or not
		if (true) {
			// n is a prime no.
			cout << n << endl;
		}
	}
}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}