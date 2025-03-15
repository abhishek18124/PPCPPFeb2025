#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << p * r * t / 100 << endl;
	cout << (p * r * t) / 100 << endl;
	cout << p * r * t / 100.0 << endl;
	cout << (float)p * r * t / 100 << endl;

	float si = float(p) * r * t / 100; // (float)p or float(p) or static_cast<float>(p)
	cout << si << endl;

	return 0;
}