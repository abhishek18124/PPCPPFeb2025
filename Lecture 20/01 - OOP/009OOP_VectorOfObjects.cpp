#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		name = n;
		age = a;
		gender = g;
		credits = c;
	}
};

// return true if you want a to be ordeed before b
// otherwise return false

bool ageCmp(customer a, customer b) {
	if (a.age < b.age) {
		// return true since we are sorting on age in inc. order
		return true;
	}
	return false;
}

class creditsCmp {

public:

	// return true if you want a to be ordered before b
	// otherwise return false

	bool operator()(customer a, customer b) {
		if (a.credits < b.credits) {
			return true;
		}
		return false;
	}

};

int main() {

	vector<customer> v;

	// customer c1("Ramanujan", 32, 'M', 1729);
	// v.push_back(c1);

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), ageCmp);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	creditsCmp obj;
	sort(v.begin(), v.end(), obj);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}
	return 0;
}