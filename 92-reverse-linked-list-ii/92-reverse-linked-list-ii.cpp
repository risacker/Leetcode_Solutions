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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)
            return head;      
        while(left < right){
            ListNode* temp = head;
            ListNode* temp2 = head;
            int cnt1 = 1, cnt2 = 1;
            while(cnt1 < left){
                temp = temp->next;
                cnt1++;
            } 
            while(cnt2 < right){
                temp2 = temp2->next;
                cnt2++;
            }
            int x = temp->val;
            temp->val = temp2->val;
            temp2->val = x;  
            left++;
            right--;
        }
        return head;
    }
};