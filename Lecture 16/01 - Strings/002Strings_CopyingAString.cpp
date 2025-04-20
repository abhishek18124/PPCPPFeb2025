#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "hello";
	string s2 = s1;
	cout << s2 << endl;
	s2[0] = 'g'; // in C++, str is mutable,it can be changed
	cout << s1 << endl;
	cout << s2 << endl;

	string s3;
	s3 = s1;
	cout << s3 << endl;

	int x = 10;
	int y = x;
	y++;
	cout << x << endl; // 10
	cout << y << endl; // 11

	return 0;
}