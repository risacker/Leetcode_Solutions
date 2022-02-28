class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
            }
        else if (!l2) {
            return l1;
            }
        else if (!l1 && !l2) {
            return nullptr;
            }
        ListNode* cur, * temp;
        if (l1->val >= l2->val) {
            temp = l2;
            l2 = l2->next;
            }
        else {
            temp = l1;
            l1 = l1->next;
            }
        cur = temp;
        while (l1 && l2) {
            if (l1->val >= l2->val) {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
                }
            if (!l1 || !l2) {
                break;
                }
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
                }
            }
        if (l1) {
            temp->next = l1;
            }
        if (l2) {
            temp->next = l2;
            }
        return cur;
        }
    };