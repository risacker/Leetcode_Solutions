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
    int ans = INT_MAX;
    int temp = -1;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left != NULL)
            getMinimumDifference(root->left);
        if(temp >= 0)
            ans = min(ans, root->val - temp);
        temp = root->val;
        if(root->right != NULL)
            int rightAns = getMinimumDifference(root->right);
        return ans; 
    }
};