class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            if (strs.empty())
                return "";
            string ans = "";
            for (int i = 0; i < strs[0].size(); i++)
            {
                bool same = true;
                for (int j = 1; j < strs.size(); j++)
                    same &= strs[j][i] == strs[j-1][i];
                if (same)
                    ans += strs[0][i];
                else
                    return ans;
            }
            return ans;
        }
};
