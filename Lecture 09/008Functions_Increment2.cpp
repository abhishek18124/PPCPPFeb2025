#include<iostream>

using namespace std;

void incr(int& ref) {
	ref++;
}

int main() {

	int a = 0;

	cout << "inside main() before incr() a = " << a << endl;

	incr(a);

	cout << "inside main() after incr() a = " << a << endl;

	return 0;
}