class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int>& A)
        {
            if (A.size() < 3)
                return 0;
            vector<int> dp(A.size(), 0);
            if ((A[2]-A[1]) == (A[1]-A[0]))
                dp[2] = 1;
            int result = dp[2];
            for (int i = 3; i < A.size(); i++)
            {
                if ((A[i]-A[i-1]) == (A[i-1]-A[i-2]))
                    dp[i] = dp[i-1] + 1;
                result += dp[i];
            }
            return result;
        }
};
