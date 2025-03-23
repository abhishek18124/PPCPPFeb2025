#include<iostream>

using namespace std;

int main() {

	const int x = 10;
	cout << x << endl;
	// x++; // error : since x is const var, we cannot modify x

	// const int y; // error : const var. must be initialized

	return 0;

}