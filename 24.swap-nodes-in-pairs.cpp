/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
        ListNode *swapPairs(ListNode *head)
        {
            if (head == NULL)
                return head;
            ListNode **pp = &head;
            ListNode *cur = head;
            ListNode *next = cur->next;
            while (cur != NULL && next != NULL)
            {
                cur->next = next->next;
                next->next = cur;
                *pp = next;
                pp = &cur->next;
                cur = cur->next;
                if (cur != NULL)
                    next = cur->next;
            }
            return head;
        }
};
