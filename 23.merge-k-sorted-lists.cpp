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
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            if (lists.size() == 1)
                return lists[0];
            ListNode *ans = NULL;
            for (int i = 0; i < lists.size(); i++)
            {
                if (ans == NULL)
                    ans = mergeTwoLists(lists[i], lists[i++]);
                else
                    ans = mergeTwoLists(ans, lists[i]);
            }
            return ans;
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
        {
            ListNode *ans = new ListNode(0);
            ListNode *ans_ptr = ans;
            while (l1 != NULL && l2 != NULL)
            {
                if (l1->val < l2->val)
                {
                    ans_ptr->next = l1;
                    l1 = l1->next;
                    ans_ptr = ans_ptr->next;
                }
                else
                {
                    ans_ptr->next = l2;
                    l2 = l2->next;
                    ans_ptr = ans_ptr->next;
                }
            }
            if (l1 == NULL)
                ans_ptr->next = l2;
            else if (l2 == NULL)
                ans_ptr->next = l1;
            return ans->next;
        }
};
