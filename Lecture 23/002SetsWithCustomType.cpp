#include<iostream>
#include<set>

using namespace std;

class customer {
public:
	string name;
	int age;
	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class ageCmp {

public:

	// return true if you want a to be ordered before b
	// otherwise return false

	bool operator()(customer a, customer b) const {
		if (a.age < b.age) {
			// we want a to be ordered before b since we are
			// maintaining a set of customers in inc. order
			// based on customer age
			return true;
		}
		return false;
	}

};

int main() {

	set<customer, ageCmp> s;

	s.insert(customer("riya", 19));
	s.insert(customer("keshav", 20));
	s.insert(customer("ayush", 18));
	s.insert(customer("soumya", 21));
	s.insert(customer("pranjal", 17));

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	return 0;
}