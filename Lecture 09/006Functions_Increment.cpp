#include<iostream>

using namespace std;

void incr(int a) {
	cout << "inside incr() before ++ a = " << a << endl;
	a++;
	cout << "inside incr() after ++ a = " << a << endl;
}

int main() {

	int a = 0;

	cout << "inside main() before incr() a = " << a << endl;

	incr(a);

	cout << "inside main() after incr() a = " << a << endl;

	// a is not modifed after fn call since we are passing
	// by value i.e. we are sending copy of 'a' declared w/i
	// main() to the incr()

	return 0;
}