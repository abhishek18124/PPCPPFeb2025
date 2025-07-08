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

bool flag = false; // assume path not found

void dfs(TreeNode* root, int target, vector<int>& path) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->val == target) {
		// you've found the path from root to target
		path.push_back(root->val);
		flag = true;
		return;
	}

	// recursive case

	path.push_back(root->val);
	dfs(root->left, target, path);
	if (flag == true) return;
	dfs(root->right, target, path);
	if (flag == true) return;
	path.pop_back();


}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(9);
	root->left->right = new TreeNode(8);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int target = 8;

	vector<int> path;

	dfs(root, target, path);

	for (auto x : path) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}