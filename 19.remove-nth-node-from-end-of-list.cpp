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
            ListNode* ptr = head;
            int count = 0;
            while (ptr != NULL)
            {
                count += 1;
                ptr = ptr->next;
            }

            int eliminate_nth = count-n+1;
            int pre_eliminate_nth = eliminate_nth-1;
            if (pre_eliminate_nth == 0)
                return head->next;
            int move_time = pre_eliminate_nth-1;
            ptr = head;
            for (int i = 0; i < move_time; i++)
                ptr = ptr->next;
            ptr->next = ptr->next->next;
            return head;
        }
};
