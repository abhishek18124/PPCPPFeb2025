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

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {
			return "";
		}

		// recursive case

		// f(root) = build the string for the given tree

		// 1. ask your friend to build the string for the leftSubtree

		string leftStr = dfs(root->left);

		// 2. ask your friend to build the string for the rightSubtree

		string rightStr = dfs(root->right);

		if (root->left != NULL and root->right != NULL) {
			return to_string(root->val) + "(" + leftStr + ")(" + rightStr + ")";
		} else if (root->left != NULL) {
			return to_string(root->val) + "(" + leftStr + ")";
		} else if (root->right != NULL) {
			return to_string(root->val) + "()(" + rightStr + ")";
		} else {
			return to_string(root->val);
		}

	}

	string tree2str(TreeNode* root) {
		return dfs(root);
	}
};