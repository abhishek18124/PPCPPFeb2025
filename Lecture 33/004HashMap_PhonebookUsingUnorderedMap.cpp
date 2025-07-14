/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using a map or an unordered_map.

*/

#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main() {

	// (string) -> vector<string>

	// Harshit -> 1234, 5678
	// Mehardeep -> 0123, 456789, 00000
	// Khushi -> 12345

	// in map<> keys are sorted
	// each ops (insert/erase/find) is O(logn)

	// in unordered_map<> keys are unordered
	// each ops (insert/erase/find) is on avg. const but worst case linear

	map<string, vector<string>> phoneMap;

	phoneMap["Harshit"].push_back("1234");
	phoneMap["Harshit"].push_back("5678");
	phoneMap["Mehardeep"].push_back("0123");
	phoneMap["Mehardeep"].push_back("456789");
	phoneMap["Khushi"].push_back("12345");

	for (pair<string, vector<string>> contact : phoneMap) {
		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [contactName, phoneNums] : phoneMap) {
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}