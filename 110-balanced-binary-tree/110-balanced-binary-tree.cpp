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
    int height(TreeNode *root){
      if(root == NULL)  
          return 0;
      int leftAns = height(root->left);
      int rightAns = height(root->right);
      int ans = max(leftAns,rightAns)+1;
      return ans;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool h = abs(height(root->left) - height(root->right)) <= 1;
        if(left && right && h)
            return true;
        else
            return false;
    }
};