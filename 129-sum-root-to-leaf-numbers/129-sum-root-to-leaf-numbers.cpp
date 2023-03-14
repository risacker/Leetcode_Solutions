class Solution {
public:
    int res = 0;
    void rec(TreeNode* node, int curr) {
        if (!node) return;
        
        curr = curr * 10 + node->val;
        
        if (!node->left && !node->right) {
            res += curr;
            return;
        }
        
        rec(node->left, curr);
        rec(node->right, curr);
    }
    
    int sumNumbers(TreeNode* root) {
        rec(root, 0);
        return res;
    }
};