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
    void findRootPath(TreeNode* root, string& path) {
        if (root == NULL) {
            path += "NULL,";
            return;
        }
        path += (to_string(root->val) + ",");
        findRootPath(root->left, path);
        findRootPath(root->right, path);
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> myMap;
        queue<TreeNode*> myQ;
        
        if (root == NULL)
            return result;

        // Add our initial root to the queue.
        myQ.push(root);
        
        // BFS search over all nodes.
        while (!myQ.empty()) {
            TreeNode* current = myQ.front();
            myQ.pop();
    
            string path = "";        
            findRootPath(current, path);
            
            // If this path isn't in the map, add it.
            if (!myMap[path]) {
                myMap[path] = 1; 
            } 
            else if (myMap[path] == 1) {
                myMap[path]++;
                result.push_back(current);    
            }
                        
            if (current->left != NULL)
                myQ.push(current->left);
            
            if (current->right != NULL)
                myQ.push(current->right);
            
        }
        
        return result;
    }
};