#include <vector>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        else {
            vector<int> left = inorderTraversal(root->left);
            for (int i = 0; i < left.size(); i++) {
                res.push_back(left[i]);
            }
            res.push_back(root->val);
             vector<int> right = inorderTraversal(root->right);
            for (int i = 0; i < right.size(); i++) {
                res.push_back(right[i]);
            }
        }
        return res;
    }
};