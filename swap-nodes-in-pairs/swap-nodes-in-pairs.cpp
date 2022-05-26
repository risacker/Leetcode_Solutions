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
    ListNode* swapPairs(ListNode* head) {
        ListNode* firstNode;
        ListNode* secondNode;
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return head;
        else{
            firstNode = head;
            secondNode = head->next;
            firstNode->next = swapPairs(secondNode->next);
            secondNode->next = firstNode;
        }
        return secondNode;
    }
};