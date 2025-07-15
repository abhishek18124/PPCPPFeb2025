/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* buildTree() {

	int x;
	cin >> x;

	if (x == -1) {
		TreeNode* root = NULL;
		// root represents an empty tree
		return root;
	}

	TreeNode* root = new TreeNode(x);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

// time : O(nlogn) since we are using a map<> and each op in a map<> takes logn
// space: O(n) due map<> + function call stack

void dfs(TreeNode* root, map<int, vector<int>>& distmap, int dist) {

	// base case

	if (root == NULL) {
		return;
	}

	// recursive case

	distmap[dist].push_back(root->val);
	dfs(root->left, distmap, dist - 1);
	dfs(root->right, distmap, dist + 1);

}

int main() {

	TreeNode* root = NULL; // init tree is empty
	root = buildTree();

	map<int, vector<int>> distmap;

	dfs(root, distmap, 0);

	for (pair<int, vector<int>> p : distmap) {
		int dist = p.first;
		vector<int> nodevals = p.second; // value of all nodes at 'dist'
		cout << dist << " : ";
		for (int val : nodevals) {
			cout << val << " ";
		}
		cout << endl;

	}

	return 0;
}

