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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int l = 0;
        while(temp){
            temp = temp->next;
            l++;
        }
        if(l == n)
            return head->next;
        ListNode* p = head;
        int j = 0;
        for(int i = 0; i < l-n-1; i++){
            p = p->next;
            j++;
        }
        cout << j;
        ListNode* del = p->next;
        p->next = del->next;
        delete del;
        return head;
    }
};