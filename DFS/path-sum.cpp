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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = targetSum;
        if (root == NULL) {
            return false;
        }
        else {
            sum -= (root->val); 
            if (sum == 0 && root->left == NULL && root->right == NULL) return true;
            else {
                if (hasPathSum(root->left, sum)) return true;
                else if (hasPathSum(root->right,sum)) return true;
            }
        }
    return false;
    }
};