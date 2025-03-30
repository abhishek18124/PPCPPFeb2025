#include<iostream>

using namespace std;

void isEven(int n) {
	if (n % 2 == 0) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}
}

int main() {

	isEven(2);

	isEven(3);

	return 0;

}