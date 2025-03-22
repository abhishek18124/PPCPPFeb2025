#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;
	while (i <= n) {
		// print 'i' nos. in the ith row
		int j = 1;
		int num = 1;
		while (j <= i) {
			cout << num << " ";
			num++;
			j++;
		}
		cout << endl;
		i++;
	}

	return 0;
}