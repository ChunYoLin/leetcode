class Solution
{
    public:
        vector<vector<int>> generate(int numRows)
        {
            if (numRows == 0)
                return {};
            vector<vector<int>> ans;
            ans.push_back(vector<int>{1});
            for (int i = 2; i <= numRows; i++)
            {
                vector<int> tmp;
                for (int j = 0; j < i; j++)
                {
                    int left = j-1 < 0 ? 0 : ans[i-2][j-1];
                    int right = j >= ans[i-2].size() ? 0 : ans[i-2][j];
                    tmp.push_back(left+right);
                } 
                ans.push_back(tmp);
            }
            return ans;
        }
};
