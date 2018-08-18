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
            ListNode **pp = &head;
            ListNode *cur, *next;
            while ((cur = *pp) && (next = cur->next))
            {
                cur->next = next->next;
                next->next = cur;
                *pp = next;
                pp = &cur->next;
            }
            return head;
        }
};
