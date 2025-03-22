#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) { // visibility / scope of loop var. i is limited to the 'for' loop only
		cout << i << " ";
	}

	cout << endl;

	cout << i << endl; // error since i is out-of-scope

	return 0;

}