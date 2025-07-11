/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

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

// class ageComparator {

// public:

// 	// return true if you want a to be ordered before b
// 	// otherwise return false

// 	bool operator()(customer a, customer b) {
// 		if (a.age < b.age) {
// 			// since we are building minHeap based on customer
// 			// age when a.age is less than b.age we want to go
// 			// before b hence we are returning true
// 			return true;
// 		}
// 		return false;
// 	}

// };

class ageComparator {

public:

	// return false if you want a to be given more priority than b
	// otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since we are building minHeap based on customer
			// age when a.age is less than b.age we want a to
			// be give more priority than b hence we are returning
			// false
			return false;
		}
		return true;
	}

};


int main() {

	priority_queue<customer, vector<customer>, ageComparator> m; // minHeap on customer age

	m.push(customer("khushi", 18));
	m.push(customer("dhruv", 20));
	m.push(customer("hiya", 17));
	m.push(customer("riya", 19));
	m.push(customer("nitin", 22));

	while (!m.empty()) {
		customer c = m.top();
		m.pop();
		cout << c.name << " " << c.age << endl;
	}

	cout << endl;

	return 0;
}