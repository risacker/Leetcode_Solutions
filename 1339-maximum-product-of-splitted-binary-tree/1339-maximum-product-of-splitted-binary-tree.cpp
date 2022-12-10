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
int sum(TreeNode* root, vector<long long>& ans){
    if(!root) 
        return 0;
    int ls = sum(root->left, ans);
    int rs = sum(root->right, ans);
    int sum = ls + rs + root->val;
    ans.push_back(sum);
    return sum;
 }

int maxProduct(TreeNode* root) {
    int mod = 1e9+7;
    vector<long long> ans;
    sum(root, ans);
    long long maxm = LLONG_MIN;
    for(int i = 0; i < ans.size() - 1; i++){
        maxm = max(maxm, ans[i]*(ans[ans.size()-1] - ans[i]));
    }
    return maxm%mod;
 }
};