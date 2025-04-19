#include<iostream>
#include<cstring>

using namespace std;

int findLength(char str[]) { // by default, char[] is passed by reference

	int cntr = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		cntr++;
	}
	return cntr;

}

int main() {

	char str[] = "hello world";

	cout << findLength(str) << endl;

	cout << strlen(str) << endl;

	return 0;
}