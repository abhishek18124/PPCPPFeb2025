#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// if you init multiple loop var. w/i the for-loop
	// you've to make sure they have the same type

	for (int i = 1, j = n; i < j; i++, j--) {
		cout << i << " " << j << endl;
	}

	cout << endl;

	// infinite loop

	// for (;;) {
	// 	cout << ".";
	// }

	return 0;

}