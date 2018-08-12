class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            if (strs.empty())
                return "";
            string ans = "";
            auto cmp_size = [&](string s1, string s2) -> bool { return s1.size() < s2.size(); };
            int min_size = min_element(strs.begin(), strs.end(), cmp_size)->size();
            for (int i = 0; i < min_size; i++)
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
