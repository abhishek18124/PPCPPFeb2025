#include<iostream>
#include<vector>

using namespace std;

void f(const vector<int>& v) { // here, v[] is passed by const ref so no copy is done, but we can only access elements of v[], they cannot be modified

	for (int i = 0; i < v.size(); i++) {
		// cout << v[i] << " ";
		v[i]++;
	}

	cout << endl;

}

int main() {

	vector<int> v = {0, 1, 2, 3, 4};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	f(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}