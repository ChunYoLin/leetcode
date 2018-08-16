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
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode *first = new ListNode(0);
            first->next = head;
            ListNode *second = first;
            for (int i = 0; i < n+1; i++)
                second = second->next;
            while (second != NULL)
            {
                first = first->next;    
                second = second->next;
            }
            if (first->next == head)
                return head->next;
            first->next = first->next->next;
            return head;
        }
};
