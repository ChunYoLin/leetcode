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
        ListNode* partition(ListNode* head, int x)
        {
            ListNode* left_half = nullptr;
            ListNode* left_half_tail = nullptr;

            ListNode* iter = head;
            ListNode* pre = nullptr;
            while (iter != nullptr)
            {
                if (iter->val < x)
                {
                    if (head == iter)
                        head = head->next;
                    if (pre != nullptr)
                        pre->next = iter->next;
                        
                    if (left_half == nullptr)
                    {
                        left_half = iter;
                        left_half_tail = left_half;
                    }
                    else
                    {
                        left_half_tail->next = iter; 
                        left_half_tail = left_half_tail->next;
                    }
                }
                else
                    pre = iter;
                iter = iter->next; 
            }
            if (left_half == nullptr)
                return head;
            else
            {
                left_half_tail->next = head;
                return left_half;
            }
        }
};
