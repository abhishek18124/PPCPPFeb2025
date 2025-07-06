#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl; // 0
	cout << "empty : " << q.empty() << endl; // true

	q.push(10);
	q.push(20);
	q.push(30); // 10 20 30

	cout << "size : " << q.size() << endl; // 3
	cout << "front : " << q.front() << endl; // 10

	q.pop(); // 10 popped

	cout << "size : " << q.size() << endl; // 2
	cout << "front : " << q.front() << endl; // 20

	q.pop(); // 20 popped

	cout << "size : " << q.size() << endl; // 1
	cout << "front : " << q.front() << endl; // 30

	q.pop(); // 30 popped
	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is not empty!" << endl;

	return 0;
}