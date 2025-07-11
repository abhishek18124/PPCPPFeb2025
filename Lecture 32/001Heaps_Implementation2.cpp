/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class maxHeap {

	vector<int> v; // internal repr of maxHeap

	void heapify(int i) { // time : logn

		// fix the maxHeap prop. at node with index i

		int maxIdx = i;

		int leftIdx = 2 * i + 1;
		if (leftIdx < v.size() and v[leftIdx] > v[maxIdx]) {
			maxIdx = leftIdx;
		}


		int rightIdx = 2 * i + 2;
		if (rightIdx < v.size() and v[rightIdx] > v[maxIdx]) {
			maxIdx = rightIdx;
		}

		if (maxIdx != i) {
			swap(v[i], v[maxIdx]);
			heapify(maxIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {

		v.push_back(val);

		int childIdx = v.size() - 1;
		int parentIdx = childIdx % 2 == 0 ? (childIdx / 2) - 1 : childIdx / 2;

		while (parentIdx != -1 and v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 0 ? (childIdx / 2) - 1 : childIdx / 2;
		}

	}

	// time : O(logn)

	void pop() {

		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // fixes the maxHeap prop. at index 0 i.e. root node // logn

	}

	// time : O(1)

	int top() {
		return v[0];
	}

	// time : O(1)

	int size() {
		return v.size();
	}

	// time : O(1)

	bool empty() {
		return v.empty();
	}

};

int main() {

	maxHeap m;

	m.push(5);
	m.push(7);
	m.push(1);
	m.push(8);
	m.push(4);
	m.push(6);
	m.push(9);
	m.push(3);
	m.push(2);

	cout << m.size() << endl; // 9

	while (!m.empty()) {
		cout << m.top() << " "; // 9 8 7 6 5 4 3 2 1
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}



