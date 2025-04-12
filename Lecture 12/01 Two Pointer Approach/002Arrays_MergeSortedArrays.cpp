#include<iostream>
#include<vector>

using namespace std;

// time : O(n+m)

void merge(const vector<int>& a, const vector<int>& b, int n, int m) {

	vector<int> c(n + m);

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]
	int k = 0; // to iterate over c[]

	while (i <= n - 1 and j <= m - 1) {

		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
			k++;
		} else {
			c[k] = b[j];
			j++;
			k++;
		}

	}

	while (i <= n - 1) { // copy remaining elements of a[] to c[]
		c[k] = a[i];
		i++;
		k++;
	}

	while (j <= m - 1) { // copy remaining elements of b[] to c[]
		c[k] = b[j];
		j++;
		k++;
	}

	for (int x : c) {
		cout << x << " ";
	}

	cout << endl;

}

int main() {

	vector<int> a = {10, 30, 50, 70};
	vector<int> b = {20, 40, 60};

	int n = a.size();
	int m = b.size();

	merge(a, b, n, m);

	return 0;
}

