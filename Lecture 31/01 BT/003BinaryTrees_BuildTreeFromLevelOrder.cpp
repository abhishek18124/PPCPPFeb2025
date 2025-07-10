/*

given the level order traversal of a binary tree, design an algorithm to construct a
binary tree from it.

Example
	Input: 10 20 30 40 50 -1 60 -1 -1 70 -1 -1 -1 -1 -1
*/

#include<iostream>
#include<queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}

}

TreeNode* buildTree() {

	int val;
	cin >> val;

	TreeNode* root = new TreeNode(val);
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		TreeNode* front = q.front();
		q.pop();

		int leftChildVal;
		cin >> leftChildVal;

		if (leftChildVal != -1) {
			// front node has a left child
			TreeNode* leftChildPtr = new TreeNode(leftChildVal);
			front->left = leftChildPtr;
			q.push(leftChildPtr);
		}

		int rightChildVal;
		cin >> rightChildVal;
		if (rightChildVal != -1) {
			// front node has a right child
			TreeNode* rightChildPtr = new TreeNode(rightChildVal);
			front->right = rightChildPtr;
			q.push(rightChildPtr);
		}

	}

	return root;

}


int main() {

	TreeNode* root = buildTree();
	printLevelOrder(root);

	return 0;
}