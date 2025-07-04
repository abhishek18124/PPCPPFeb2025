#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

// time : O(n)
// space: O(1)

bool searchIterative(ListNode* head, int t) {

	while (head != NULL) {
		if (head->val == t) {
			return true;
		}
		head = head->next;
	}
	return false; // t not found

}

// time : O(n)
// space: O(n) due to fn call stack

bool searchRecursive(ListNode* head, int t) {

	// base case

	if (head == NULL) {
		// linkedList is empty
		return false;
	}

	// recursive case

	if (head->val == t) {
		return true;
	} else {
		// ask your friend to search for t in the sublist that starts
		// from the node which comes after the head node
		return searchRecursive(head->next, t);
	}

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int t = 30;

	searchIterative(head, t) ? cout << "true" << endl : cout << "false" << endl;

	searchRecursive(head, t) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}