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
    unsigned long long int sum, cnt = 0;
    void dfs(TreeNode* root, unsigned long long int label){
        if(!root)
            return;
        cnt++;
        sum += label;
        dfs(root->left, 2*label);
        dfs(root->right, 2*label+1);
    }
    
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 1);       
        return (cnt * (cnt + 1) / 2 == sum);
    }
};