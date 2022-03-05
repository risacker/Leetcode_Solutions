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
    int sum = 0;
    bool isLeft(TreeNode* root){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        //int sum = 0;
        if(isLeft(root->left)){
            sum += root->left->val;
        }
        int leftSum = sumOfLeftLeaves(root->left);
        int rightSum = sumOfLeftLeaves(root->right);
        return sum;
    }
};