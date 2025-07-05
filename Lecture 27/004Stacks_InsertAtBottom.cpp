#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) { // by default stack<int> is passed by value,
	// so any changes done to s within this fn won't be reflected in the main()

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int data = 0;

	stack<int> temp;

	// 1. transfer elements from s to temp => 3n steps

	while (!s.empty()) {
		temp.push(s.top());
		s.pop();
	}

	// 2. insert data into s => 1 step

	s.push(data);

	// 3. transfer elements from temp to s => 3n steps

	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}

	// total steps = (6n+1).const therefore time : O(n)
	// space : O(n) due temp stack

	print(s);

	return 0;
}