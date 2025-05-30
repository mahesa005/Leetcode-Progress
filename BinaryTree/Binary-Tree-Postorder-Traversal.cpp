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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        else if (root->left == nullptr && root->right == nullptr) {
            result.push_back(root->val);
            return result;
        }
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        left.insert(left.end(), right.begin(), right.end());
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        return result;
    }
};