/*

    Given k sorted linked list, merge them and print the sorted output.

    k = 3
    Input : 0->3->6
            1->4->7
            2->5->8

    Output: 0->1->2->3->4->5->6->7->8

*/

#include<iostream>
#include<queue>
#include<vector>

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

class ListNodeComp {

public:

    // return false if you a to be given more priority otherwise return true

    bool operator()(ListNode* a, ListNode* b) {
        if (a->val < b->val) {
            return false;
        }
        return true;
    }

};

// time : O(nklogk)
// space: O(k) due to minHeap

ListNode* mergeKSortedLinkedList(vector<ListNode*>& v) {

    priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> minHeap(v.begin(), v.end());

    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while (!minHeap.empty()) {

        ListNode* minNode = minHeap.top();
        minHeap.pop();

        temp->next = minNode;
        temp = temp->next;

        if (minNode->next != NULL) {
            minHeap.push(minNode->next);
        }

    }

    return dummy->next;

}

int main() {

    ListNode* head1 = NULL;

    insertAtHead(head1, 70);
    insertAtHead(head1, 40);
    insertAtHead(head1, 10);

    printLinkedList(head1);

    ListNode* head2 = NULL;

    insertAtHead(head2, 80);
    insertAtHead(head2, 50);
    insertAtHead(head2, 20);

    printLinkedList(head2);

    ListNode* head3 = NULL;

    insertAtHead(head3, 90);
    insertAtHead(head3, 60);
    insertAtHead(head3, 30);

    printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3};

    ListNode* head = mergeKSortedLinkedList(v);

    printLinkedList(head);

    return 0;
}
