#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl; // 10

	{
		int y = 20;

		cout << x << " " << y << endl; // 10 20

	}

	return 0;
}