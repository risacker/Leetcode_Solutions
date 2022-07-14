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
     unordered_map<int,int> mp;
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0;i < n;i++){
            mp[inorder[i]] = i;
        }   
        return build(preorder, inorder, 0, 0, n-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int curr, int l,int r){   
		if(l > r)
            return nullptr;
        int idx = mp[preorder[curr]], left_subtree_len = idx-l;
        TreeNode *root = new TreeNode(preorder[curr]);
        root->right = (build(preorder, inorder, curr+left_subtree_len+1, idx+1, r));
        root->left = (build(preorder, inorder, curr+1, l, idx-1)); 
        return root;
    }
};