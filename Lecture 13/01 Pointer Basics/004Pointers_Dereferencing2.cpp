#include<iostream>

using namespace std;

int main() {

	int x = 516;
	char* ptr = (char*) &x;
	cout << x << endl;
	cout << (int)*ptr << endl;

	return 0;
}