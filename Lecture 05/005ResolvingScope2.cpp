#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl; // 10

	{
		int x = 30;
		int y = 20;

		cout << x << " " << y << endl; // 30 20

	}

	return 0;
}