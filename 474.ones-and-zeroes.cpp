class Solution
{
    public:
        int findMaxForm(vector<string>& strs, int m, int n)
        {
            vector<vector<int>> total(m+1, vector<int>(n+1, 0));
            for (auto &s : strs)
            {
                int numof0 = count(s.begin(), s.end(), '0');
                int numof1 = count(s.begin(), s.end(), '1');
                for (int i = m; i >= numof0; i--)
                    for (int j = n; j >= numof1; j--)
                        total[i][j] = max(total[i][j], total[i-numof0][j-numof1] + 1);
            }
            return total[m][n];
        }
};
