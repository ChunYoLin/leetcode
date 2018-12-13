class Solution
{
    public:
        int minFallingPathSum(vector<vector<int>>& A)
        {
            for (int i = 1; i < A.size(); i++)
                for (int j = 0; j < A[0].size(); j++)
                    A[i][j] += min({A[i-1][j], A[i-1][max(0, j-1)], A[i-1][min((int)A.size()-1, j+1)]});
            return *min_element(A.back().begin(), A.back().end());
        }
};
