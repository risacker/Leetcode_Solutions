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
    vector<TreeNode*> check(int start, int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i = start; i <= end ; i++){
            vector<TreeNode*> left = check(start, i-1);
            vector<TreeNode*> right = check(i+1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode *temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return check(1, n);
    }
};