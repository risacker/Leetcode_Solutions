/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void distanceK_find_child_at_distance(TreeNode* root, int k, int level, vector<int> &ans){
        if(root == NULL){
            return ;
        }  
        if(level > k){
            return;
        }       
        if(level == k){
            ans.push_back(root->val);
        }      
        distanceK_find_child_at_distance(root->left, k, level + 1, ans);
        distanceK_find_child_at_distance(root->right, k, level + 1, ans);
    }
    
    int distanceK_find_target(TreeNode* root, TreeNode* target, int k, vector<int> &ans){
        if (root == NULL){
            return -1;
        }       
        if(root->val == target->val){
            return 1;
        }        
        int a = distanceK_find_target(root->left, target, k, ans);
        if(a > 0){
            if (a == k){
                ans.push_back(root->val);
            } 
            else{
                distanceK_find_child_at_distance(root->right, k, a + 1, ans);
            }
            return a + 1;
        }
        
        int b = distanceK_find_target(root->right, target, k, ans);

        if(b > 0){
            if(b == k){
                ans.push_back(root->val);
            } 
            else{
                distanceK_find_child_at_distance(root->left, k, b + 1, ans);
            } 
            return b + 1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;     
        distanceK_find_child_at_distance(target, k, 0, ans);   
        distanceK_find_target(root, target, k, ans);   
        return ans;
    }
};