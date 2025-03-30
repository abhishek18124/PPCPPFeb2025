#include<iostream>

using namespace std;


int main() {

	int a = 20;
	int& b = a;
	b++;
	cout << a << endl;

	return 0;
}