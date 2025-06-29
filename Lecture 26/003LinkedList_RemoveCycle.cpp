#include<iostream>

using namespace std;

class ListNode {
public:

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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

// time : O(n)
// space: O(1)

void removecycle(ListNode* head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// you've reached the meeting point
			break;
		}
	}

	slow = head; // move slow to head

	ListNode* prev = head; // move prev to one-step behind meeting point / fast
	while (prev->next != fast) {
		prev = prev->next;
	}

	while (slow != fast) { // move slow, fast, prev at same speed till slow and fast meet
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	// slow becomes equal to fast it means they are at the start
	// of the cycle therefore prev must be at the tail node of the
	// linkedList

	prev->next = NULL;

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	// printLinkedList(head);

	removecycle(head);

	printLinkedList(head);

	return 0;
}