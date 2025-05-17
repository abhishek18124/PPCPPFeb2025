#include<iostream>

using namespace std;

// private members can be accessed only within the class
// public members can be accessed within and outside the class

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	c1.print(); // addr of c1 is passed implicitly during this fn call

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	c2.print(); // addr of c2 is passed implicitly during this fn call

	return 0;
}