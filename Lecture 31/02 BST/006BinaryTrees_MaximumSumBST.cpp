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

class Data {
public :
    int sum;
    int minVal;
    int maxVal;
    bool isBST;
    int maxBSTSum;
};

class Solution {
public:

    // time : O(n)
    // space: O(hgt of tree) due to fn call stack

    Data dfs(TreeNode* root) {

        Data d;

        // base case

        if (root == NULL) {
            d.sum = 0;
            d.minVal = INT_MAX;
            d.maxVal = INT_MIN;
            d.isBST = true;
            d.maxBSTSum = 0;
            return d;
        }

        // recursive case

        Data left = dfs(root->left);
        Data right = dfs(root->right);

        d.sum = left.sum + right.sum + root->val;
        d.minVal = min(left.minVal, min(right.minVal, root->val));
        d.maxVal = max(left.maxVal, max(right.maxVal, root->val));
        d.isBST = left.isBST and right.isBST and (root->val > left.maxVal and root->val < right.minVal);

        if (d.isBST) {
            d.maxBSTSum = max(left.maxBSTSum, max(right.maxBSTSum, d.sum));
        } else {
            d.maxBSTSum = max(left.maxBSTSum, right.maxBSTSum);
        }

        return d;
    }

    int maxSumBST(TreeNode* root) {
        Data d = dfs(root);
        return d.maxBSTSum;
    }
};