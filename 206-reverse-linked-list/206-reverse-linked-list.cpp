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
class Solution {
public:
   ListNode* reverseList(ListNode* head) {
    stack<ListNode*> stk;
     while(head){
         stk.push(head);
         head=head->next;
     }
     if(stk.empty()) 
         return nullptr;
     ListNode* t;
     t=head=stk.top();stk.pop();
     while(!stk.empty()) 
         t->next=stk.top(),stk.pop(),t=t->next;
     t->next=NULL;
     return head;
    }
};