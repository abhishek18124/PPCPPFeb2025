#include<iostream>

using namespace std;

int multiply(int x, int y) {
	return x * y;
}

int main() {

	int a, b;
	cin >> a >> b;

	cout << multiply(a, b) << endl;

	return 0;
}