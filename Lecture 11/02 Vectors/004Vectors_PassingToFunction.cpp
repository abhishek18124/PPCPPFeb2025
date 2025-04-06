#include<iostream>
#include<vector>

using namespace std;

void f(vector<int> v) { // vector<int> are by default passed by value

	for (int i = 0; i < v.size(); i++) {
		v[i]++;
	}

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