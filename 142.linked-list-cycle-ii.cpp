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

        ListNode *detectCycle(ListNode *head)
        {
            if (head == NULL || head->next == NULL)
                return NULL;

            ListNode* slow = head;
            ListNode* fast = head;

            while (fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                {
                    while (slow != head)
                    {
                        slow = slow->next;
                        head = head->next;
                    }
                    return head;
                }
            }
            return NULL;
        }
};
