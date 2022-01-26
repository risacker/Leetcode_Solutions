class Solution {
public:
    vector<int> vec;
    void insort(TreeNode* root)
    {
        if(root==NULL) 
            return;
        insort(root->left);
        vec.push_back(root->val);
        insort(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        insort(root1);
        insort(root2);
        sort(vec.begin(),vec.end());
          return vec;     
    }
};