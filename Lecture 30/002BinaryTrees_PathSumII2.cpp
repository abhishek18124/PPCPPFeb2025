#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& allPaths) {

	// base case

	// todo ...

	// recursive case

	// todo ...

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

	vector<vector<int>> allPaths;
	vector<int> path;

	helper(root, targetSum, path, allPaths);

	return allPaths;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	vector<vector<int>> allPaths = pathSum(root, targetSum);

	for (vector<int> path : allPaths) {
		for (int nodeVal : path) {
			cout << nodeVal << " ";
		}
		cout << endl;
	}

	return 0;
}