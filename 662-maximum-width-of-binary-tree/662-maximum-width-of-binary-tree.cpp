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
  int widthOfBinaryTree(TreeNode* root) {
    if(!root)
      return 0;
    long ans = 0;
    queue<pair<TreeNode* ,int >>q;
    q.push({root,0});
    while(q.size()){
      int sz = q.size();
      auto mn = q.front().second;
      long l;
      for(int i=0;i<sz;i++){
         int idx = q.front().second-mn;
         auto node = q.front().first;
         q.pop();
         if(i == sz-1)
           l = idx;
         if(node->left)
           q.push({node->left,(long)idx*2});
         if(node->right)
           q.push({node->right,(long)idx*2+1});
      }
      ans = max(ans,l+1);
    }
  return ans;
}
};