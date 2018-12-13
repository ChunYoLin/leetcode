class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int>& A)
        {
            if (A.size() < 3)
                return 0;
            vector<vector<bool>> table(A.size(), vector<bool>(A.size(), true));
            int ans = 0;
            for (int start = 0; start < A.size(); start++)
            {
                for (int end = start+2; end < A.size(); end++)
                {
                    table[start][end] = table[start][end-1] & (A[end] - A[end-1]) == (A[end-1] - A[end-2]);
                    ans += table[start][end];
                }
            }
            return ans;
        }
};
