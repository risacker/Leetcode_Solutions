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
    int soln(TreeNode *root, int &maxm){
        if(root==NULL)
             return 0;
        int leftAns = soln(root->left, maxm);
        int rightAns = soln(root->right, maxm);
        maxm = max(maxm, leftAns+rightAns);
        return 1+max(leftAns,rightAns);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxm = 0;
        soln(root,maxm);
        return maxm;
    }
};