#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "coding"; // str obj is terminated by '\0'

	cout << str[0] << endl;
	cout << str.front() << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;
	cout << str[4] << endl;
	cout << str[5] << endl;
	cout << str.back() << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}

	cout << endl;

	cout << str.size() << endl;

	int n = str.size();

	for (int i = 0; i < n; i++) {
		cout << str[i] << " ";
	}

	cout << endl;

	return 0;
}