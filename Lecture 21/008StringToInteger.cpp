#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (n == 0) { // str.empty() // str == ""
		return 0;
	}

	// recursive case

	// f(str) => convert 'str' to an 'int'

	string subString = str.substr(0, n - 1);
	int integerFromMyFriend = stringToInteger(subString, n - 1);
	return integerFromMyFriend * 10 + (str[n - 1] - '0');

}

int main() {

	string str = "12345";
	int n = str.size();

	int x = stringToInteger(str, n);
	cout << x << endl;

	return 0;
}