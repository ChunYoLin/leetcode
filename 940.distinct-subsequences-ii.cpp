class Solution
{
    public:
        int distinctSubseqII(string S)
        {
            int mod = 1000000007;
            vector<int> dp(S.size()+1, 0);
            vector<int> last(26, 0);
            dp[0] = 1;
            for (int i = 1; i < S.size()+1; i++)
            {
                dp[i] = dp[i-1]*2 % mod;
                char ch = S[i-1]-'a';
                if (last.at(ch) != 0)
                    dp[i] -= dp[last[ch] - 1];
                dp[i] %= mod;
                last[ch] = i;
            } 
            return (((dp[S.size()] - 1) + mod) % mod);
        }
};
