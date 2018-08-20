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
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            if(head == NULL || k == 1) return head;
            ListNode *dummy = new ListNode(-1);
            ListNode *pre = dummy, *cur = dummy, *next = dummy;
            pre->next = head;
            int num = 0;
            while (head->next != NULL)
            {
                head = head->next;
                num++;
            }
            num = num+1;
            while (num >= k)
            {
                cur = pre->next;
                next = cur->next;
                for (int i = 1; i < k; i++)
                {
                    cur->next = next->next;
                    next->next = pre->next;
                    pre->next = next;
                    next = cur->next;
                }
                pre = cur;
                num-=k;
            }

            return dummy->next;
        }
};
