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
        vector<int> nextLargerNodes(ListNode* head)
        {
            vector<int> stack, res;

            for (ListNode* node = head; node != NULL; node = node->next)
            {
                while (stack.size() && res[stack.back()] < node->val)
                {
                    res[stack.back()] = node->val;
                    stack.pop_back();
                }
                stack.push_back(res.size());
                res.push_back(node->val);
            }

            for (int i = 0; i < stack.size(); i++)
                res[stack[i]] = 0;
            return res;
        }
};
