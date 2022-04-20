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
class BSTIterator {
    vector<int> values;
    int position = 0;
public:
    void inorder(TreeNode* root){
        if(root == NULL) 
            return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* BSTroot){
        inorder(BSTroot);
    }
    
    int next(){
        return values[position++];
    }
    
    bool hasNext(){
        if(position<values.size()) 
            return 1;
        return 0; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */