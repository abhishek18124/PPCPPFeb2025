#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}
	}

	return true;

}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good" << endl :
	                         cout << "not good" << endl;

	return 0;
}