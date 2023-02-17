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
    int minDistance = INT_MAX;
    TreeNode* prevValue;
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) 
            return;
        inorderTraversal(root->left);
        if (prevValue != NULL) 
            minDistance = min(minDistance, root->val - prevValue->val);
        prevValue = root;
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);    
        return minDistance;
    }
};