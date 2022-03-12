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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!(st1.empty() and st2.empty()))
        {
            vector<int> temp;
            while (!st1.empty())
            {
                auto x = st1.top();
                st1.pop();
                temp.push_back(x->val);
                if (x->left)
                    st2.push(x->left);
                if (x->right)
                    st2.push(x->right);
            }
            if (!temp.empty())
            {
                ans.push_back(temp);
            }
            temp.clear();
            while (!st2.empty())
            {
                auto x = st2.top();
                st2.pop();
                temp.push_back(x->val);
                if (x->right)
                    st1.push(x->right);
                if (x->left)
                    st1.push(x->left);
            }
            if (!temp.empty())
            {
                ans.push_back(temp);
            }
            temp.clear();
        }
        return ans; 
    }
};