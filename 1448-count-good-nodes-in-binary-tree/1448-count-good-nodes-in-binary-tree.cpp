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
    void func(TreeNode *root, int &cnt, int temp){
        if(root == NULL)
            return;
        if(root->val >= temp)
            cnt++;
        temp = max(temp,root->val);
        func(root->left,cnt,temp);
        func(root->right,cnt,temp);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int temp = root->val;
        func(root, cnt, temp);
        return cnt;
    }
};