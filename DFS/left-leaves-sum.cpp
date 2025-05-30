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
    int sumOfLeftLeaves(TreeNode* root) {
        int sumLeft = 0;
        if (!root) {
            return 0;
        }
        if (root->left && !root->left->left && !root->left->right) {
            sumLeft += root->left->val;
        }
        sumLeft += sumOfLeftLeaves(root->left);
        sumLeft += sumOfLeftLeaves(root->right);
        return sumLeft;
    }
};