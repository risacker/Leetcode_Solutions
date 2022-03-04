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
     void traverseTree(TreeNode *root, vector<string>&res, string s){
        if(root == NULL)
            return;
         s += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(s.substr(2));
            return;
        }
        traverseTree(root->left, res, s);
        traverseTree(root->right, res, s);
      }
    
     vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        traverseTree(root, res, "");
        return res;
    }
};