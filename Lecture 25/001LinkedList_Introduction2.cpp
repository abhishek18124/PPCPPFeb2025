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

// time : O(1)

void insertAtHead(ListNode*& head, int val) { // here, head ptr is passed by reference since we want change done head ptr inside the fn to reflect in the head ptr of the caller fn i.e. main()
	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
}

// time : O(n)

void printLinkedList(ListNode* head) { // here, head ptr is passed by value since we don't want changes done to the head ptr inside this fn to reflect in the head ptr of the caller fn i.e. main()
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	ListNode* head = NULL; // init, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) {
		cout << "linkedList is empty" << endl;
	}

	printLinkedList(head);

	printLinkedList(head);

	return 0;

}