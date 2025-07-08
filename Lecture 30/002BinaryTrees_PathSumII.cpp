/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	void dfs(TreeNode* root, int targetSum,
	         vector<int>& path,
	         vector<vector<int>>& allPaths) {

		// base case

		if (root == NULL) {
			return;
		}

		if (root->left == NULL and root->right == NULL) {
			// you've reached the leaf node
			if (root->val == targetSum) {
				// you've managed to build a valid path
				path.push_back(root->val);
				allPaths.push_back(path);
				path.pop_back();
				return;
			} else {
				// you did not build a valid path
				return;
			}
		}

		// recursive case

		path.push_back(root->val);
		dfs(root->left, targetSum - root->val, path, allPaths);
		dfs(root->right, targetSum - root->val, path, allPaths);
		path.pop_back(); // backtrack

	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> path; // to track a single root-to-leaf path
		vector<vector<int>> allPaths; // to track all valid root-to-leaf paths
		dfs(root, targetSum, path, allPaths);
		return allPaths;
	}
};