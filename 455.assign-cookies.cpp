class Solution
{
    public:
        int findContentChildren(vector<int>& g, vector<int>& s)
        {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            
            int g_ptr = 0, s_ptr = 0;
            int ans = 0;
            while (g_ptr < g.size() && s_ptr < s.size())
            {
                if (g[g_ptr] <= s[s_ptr])
                {
                    g_ptr++;
                    s_ptr++;
                    ans += 1;
                }
                else if (s[s_ptr] < g[g_ptr])
                    s_ptr++;
            }
            return ans;
        }
};
