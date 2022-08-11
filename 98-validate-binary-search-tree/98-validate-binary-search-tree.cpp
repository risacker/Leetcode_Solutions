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
      bool isValid(TreeNode* root, long long minValue, long long maxValue) {
        if(root == nullptr) 
            return true;
        if(root->val >= maxValue || root->val <= minValue) 
            return false;
        return isValid(root->left, minValue, root->val) && isValid(root->right, root->val, maxValue); 
    }
    
    bool isValidBST(TreeNode* root) {
        long long small = LONG_MIN;
        long long large = LONG_MAX;
        return isValid(root, small, large);
    }
};