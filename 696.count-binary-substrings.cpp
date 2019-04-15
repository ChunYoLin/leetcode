class Solution
{
    public:
        int countBinarySubstrings(string s)
        {
            int ans = 0;
            stack<char> mystack;
            stack<char> swap_stack;
            for (int i = 0; i < s.size(); i++)
            {
                if (mystack.empty() && swap_stack.empty())
                    mystack.push(s[i]);
                else
                {
                    if (mystack.empty() || (s[i] == mystack.top() && !swap_stack.empty()))
                    {
                        mystack = swap_stack;
                        swap_stack = {};
                    }
                    if (s[i] == mystack.top())
                        mystack.push(s[i]);
                    else
                    {
                        mystack.pop();
                        swap_stack.push(s[i]);
                        ans++;
                    }
                }
            }
            return ans;
        }
};
