class Solution
{
    public:
        int distinctSubseqII(string S)
        {
            int mod = 1000000007;
            vector<int> dp(S.size()+1, 0);
            map<char, int> last;
            dp[0] = 1;
            for (int i = 1; i < S.size()+1; i++)
            {
                dp[i] = dp[i-1]*2 % mod;
                if (last.count(S[i-1]))
                    dp[i] -= dp[last[S[i-1]] - 1];
                dp[i] %= mod;
                last[S[i-1]] = i;
            } 
            return (((dp[S.size()] - 1) + mod) % mod);
        }
};
