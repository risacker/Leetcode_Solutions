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
    vector<int> post;
    void postorder(TreeNode *h){
        if(!h)  
            return;
        postorder(h->left);
        postorder(h->right);
        post.push_back(h->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return post;
    }
};