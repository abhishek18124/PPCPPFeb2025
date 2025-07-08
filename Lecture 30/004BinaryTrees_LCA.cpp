/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	// time : O(n)

	TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {

		// base case

		if (root == NULL) {
			return NULL;
		}

		if (root == p) {
			// find the LCA(p, q) in the subtree of p
			return p;
		}

		if (root == q) {
			// find the LCA(p, q) in the subtree of q
			return q;
		}

		// recursive case

		// f(root, p, q) = find the LCA(p, q) in the given tree

		TreeNode* left = dfs(root->left, p, q);
		TreeNode* right = dfs(root->right, p, q);

		if (left != NULL and right != NULL) {
			return root;
		} else if (left != NULL and right == NULL) {
			return left;
		} else if (left == NULL and right != NULL) {
			return right;
		} else {
			return NULL;
		}

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return dfs(root, p, q);
	}
};