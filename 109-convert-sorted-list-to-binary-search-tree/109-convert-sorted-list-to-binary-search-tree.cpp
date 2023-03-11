/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) 
            return nullptr;
        if(!head->next)
            return new TreeNode(head->val); 
        if(!head->next->next){
            TreeNode* r = new TreeNode(head->val);
            r->right = new TreeNode(head->next->val);
            return r;
        }   
        ListNode*fast=head;
        ListNode*mid=head;
        ListNode*prev=mid;    
        while(fast && fast->next){
             fast = fast->next->next;
             prev = mid;
             mid= mid->next;
        }    
        TreeNode* root = new TreeNode(mid->val);
        prev->next = nullptr;
        root->left  = sortedListToBST(head);
        root->right = sortedListToBST(mid->next); 
        return root;
    }
};