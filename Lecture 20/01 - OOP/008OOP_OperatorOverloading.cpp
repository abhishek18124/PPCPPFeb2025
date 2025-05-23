#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

	bool operator>(customer& c) { // to avoid copying c2 we are passing by ref
		// if (age > c.age) {
		// 	return true;
		// } else {
		// 	return false;
		// }

		return age > c.age;
	}

	int operator+(customer& c) { // to avoid copying c2 we are passing by ref
		return age + c.age;
	}

};

// we can overload operators as non-member fn also

int operator*(customer& c1, customer& c2) {
	return c1.age * c2.age;
}

// doesn't support chaining

// void operator<<(ostream& cout, customer& c1) {
// 	cout << c1.name << " " << c1.age << " " << c1.gender << " " << c1.credits << endl;
// }

// supports chaining

ostream& operator<<(ostream& cout, customer& c1) {
	cout << c1.name << " " << c1.age << " " << c1.gender << " " << c1.credits << endl;
	return cout;
}

int main() {

	customer c1("Ramanujan", 98, 'M', 1729);
	customer c2("Aryabhata", 74, 'M', 0);

	c1 > c2 ? cout << "c1 > c2" << endl : cout << "c1 < c2" << endl;
	c1.operator > (c2) ? cout << "c1 > c2" << endl : cout << "c1 < c2" << endl;

	cout << c1 + c2 << endl; // c1.operator+(c2)

	cout << c1 * c2 << endl; // c1.operator*(c2) // operator*(c1, c2)

	// cout << c1; // operator<<(cout, c1)

	cout << c1 << c2;

	return 0;

}