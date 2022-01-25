inline void AddWithNode (int & nVal, ListNode ** node)
{
    if (nullptr != *node)    
    {
        nVal += (*node)->val;
        *node = (*node)->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *begin = nullptr, *res = nullptr;
        
        int nExtra = 0;
        while (nullptr != l1 || nullptr != l2)
        {
            int nRes = nExtra;
            AddWithNode (nRes, &l1);
            AddWithNode (nRes, &l2);            
            nExtra = nRes / 10;
            if (nullptr == res)
            {
                begin = res = new ListNode (nRes % 10);
            }
            else
            {
                res->next = new ListNode (nRes % 10);
                res = res -> next;
            }

        }
        if (0 != nExtra)
        {
            res->next = new ListNode (nExtra);
        }
        return begin;
    }
};