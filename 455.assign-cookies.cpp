class Solution
{
    public:
        int findContentChildren(vector<int>& g, vector<int>& s)
        {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            
            int ans = 0;
            int s_ptr = 0;
            for (int g_ptr = 0; g_ptr < g.size(); ++g_ptr)
            {
                while (s_ptr < s.size() && s[s_ptr] < g[g_ptr]) ++s_ptr;
                if (s_ptr < s.size())
                {
                    ++ans; 
                    ++s_ptr;
                }
                else
                    return ans;
            }
            return ans;
        }
};
