#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "hello";
	string t = "world";
	// s.append(t);
	s = s + " " + t;
	cout << s << endl;
	cout << t << endl << endl;

	string str = "codin";
	cout << str << endl;

	// str.push_back('g'); // always work
	// str = str + 'g'; // may not always work
	str += 'g'; // always work
	cout << str << endl;

	str.pop_back();
	cout << str << endl;

	for (char ch : str) {
		cout << ch << endl;
	}

	return 0;
}