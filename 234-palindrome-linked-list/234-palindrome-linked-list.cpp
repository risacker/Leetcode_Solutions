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
  bool isPalindrome(ListNode *head){
        ListNode *temp = head;
        ListNode *put = head;
        int n = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = put->val;
            put = put->next;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr[n - i - 1])
                return false;
            else
                continue;
        }
        return true;
      }
};