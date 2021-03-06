class Solution
{
    public:
        int countBinarySubstrings(string s)
        {
            int pre = 0;
            int cur = 1;
            int res = 0;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == s[i - 1]) cur++;
                else 
                {
                    pre = cur;
                    cur = 1;
                }
                if (pre >= cur)
                    res++;
            }
            return res;
        }
};
