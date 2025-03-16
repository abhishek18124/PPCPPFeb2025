#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 0; // to store the square root of n

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	cout << ans << endl;

	return 0;
}