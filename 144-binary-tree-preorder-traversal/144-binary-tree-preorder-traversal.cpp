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
   vector<int> pre;
   void preorder(TreeNode *h){
    if(!h)  
        return;
    pre.push_back(h->val);
    preorder(h->left);
    preorder(h->right);
   }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return pre;
    }
};