class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            if (s.size() < 2)
                return 0;
            vector<int> dp(s.size(), 0);

            int open = 0, ans = 0;
            for (size_t i = 0; i < s.size(); ++i)
            {
                if (s[i] == '(')
                    open++;
                if (s[i] == ')' && open > 0)
                {
                    dp[i] = dp[i-1] + 2;
                    if ((int)(i - dp[i]) > 0)
                    {
                        cout << i-dp[i] << endl;
                        dp[i] += dp[i - dp[i]];
                    }
                    open--;
                }
                if (dp[i] > ans) ans = dp[i];
            }
            return ans;
        }
};
