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

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl :
	                  cout << n << " is not prime" << endl;

	return 0;
}