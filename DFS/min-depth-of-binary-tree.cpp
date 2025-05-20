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
    int minDepth(TreeNode* root) {
        int min = 0;
        if (!root) return 0;
        else {
            if (root->left == nullptr && root->right == nullptr) {
                return 1;
            }
            else {
                if (root->left != nullptr && root->right != nullptr) {
                    min += 1 + std::min(minDepth(root->left), minDepth(root->right));
                }
                else if (root->left) {
                    min += 1 + minDepth(root->left);
                }
                else {
                    min += 1 + minDepth(root->right);
                }
            }
        }
        return min;
    }
};