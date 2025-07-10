/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	// root ptr is pointing to the leftmost node of the BST which is the minval node of the BST

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	// root ptr is pointing to the righttmost node of the BST which is the maxval node of the BST

	return root->val;

}

// time : O(n^2)

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true; // we assume empty tree is a bst since there is no BST prop. violation
	}

	// recursive case

	// f(root) = check if the given tree is a BST

	// 1. ask your friend to check if the leftSubtree is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST prop. works at the root node

	bool bstPropAtRoot = root->val > findMaximum(root->left) and
	                     root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and bstPropAtRoot;

}

class triple {

public:

	bool isBst;
	int minVal;
	int maxVal;

};

// time : O(n)
// [HW] solve this ques in O(n) without using triple class (check recording)

triple checkBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isBst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = checkBSTEfficient(root->left);
	triple right = checkBSTEfficient(root->right);
	bool bstPropAtRoot = root->val > left.maxVal and
	                     root->val < right.minVal ? true : false;

	t.isBst = left.isBst and right.isBst and bstPropAtRoot;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;


}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	triple t = checkBSTEfficient(root);

	t.isBst ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}