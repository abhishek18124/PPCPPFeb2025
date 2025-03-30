#include<iostream>

using namespace std;

bool isEven(int n) {
	return n % 2 == 0;
}

int main() {

	// if a fn call returns a value, you can treat that
	// fn call like an expression

	bool ans = isEven(2);
	cout << ans << endl;

	cout << isEven(5) << endl;

	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	if (isEven(9)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(11) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}