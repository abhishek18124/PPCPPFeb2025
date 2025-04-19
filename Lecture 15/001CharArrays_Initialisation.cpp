#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	char str2[] = "hello"; // when you init a char arr[] using string literal, '\0' is added automatically
	cout << str2 << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}

	cout << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << " ";
	}

	cout << endl;

	return 0;
}