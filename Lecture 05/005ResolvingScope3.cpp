#include<iostream>

using namespace std;

int x = 100;

int main() {

	cout << x << endl; // 100

	int x = 10;

	cout << x << endl; // 10

	{
		int x = 30;
		int y = 20;

		cout << x << " " << y << endl; // 30 20

	}

	return 0;
}