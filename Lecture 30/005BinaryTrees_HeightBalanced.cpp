
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

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


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int computeHeight(TreeNode* root) {

	// base case

	if (root == NULL) {
		return -1;
	}

	// recursive case

	// f(root) = find the height of the given tree

	// 1. ask your friend to find the height of the leftSubtree

	int hgtLST = computeHeight(root->left);

	// 2. ask your friend to find the height of the rightSubtree

	int hgtRST = computeHeight(root->right);

	return 1 + max(hgtLST, hgtRST);

}

// time : O(n^2)

bool dfs(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true; // we assume empty tree is HB since there is no violation of HB prop.
	}

	// recursive case

	// f(root) = check if the given tree is height balanced or not

	// 1. ask your friend to check if the leftSubtree is height balanced or not

	bool leftIsBal = dfs(root->left);

	// 2. ask your friend to check if the rightSubtree is height balanced or not

	bool rightIsBal = dfs(root->right);

	// 3. check if the height balance property works at the root node

	bool rootIsBal = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and rootIsBal;

}

class Pair {
public:
	int height;
	bool isBal;
};

// time : O(n)

Pair dfsOptimised(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.height = -1;
		p.isBal = true;
		return p;
	}

	// recursive case

	Pair left = dfsOptimised(root->left);
	Pair right = dfsOptimised(root->right);
	bool rootIsBal = abs(left.height - right.height) <= 1 ? true : false;

	p.height = 1 + max(left.height, right.height);
	p.isBal = left.isBal and right.isBal and rootIsBal;

	return p;

}

// time : O(n)

pair<int, bool> dfsOptimised2(TreeNode* root) {

	pair<int, bool> p;

	// base case

	if (root == NULL) {
		p.first = -1;
		p.second = true;
		return p;
	}

	// recursive case

	pair<int, bool> left = dfsOptimised2(root->left);
	pair<int, bool> right = dfsOptimised2(root->right);
	bool rootIsBal = abs(left.first - right.first) <= 1 ? true : false;

	p.first = 1 + max(left.first, right.first);
	p.second = left.second and right.second and rootIsBal;

	return p;

}

int main() {

	TreeNode* root = buildTree();

	dfs(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = dfsOptimised(root);

	p.isBal ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	pair<int, bool> p2 = dfsOptimised2(root);

	p2.second ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	return 0;
}