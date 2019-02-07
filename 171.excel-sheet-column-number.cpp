class Solution
{
    public:
        int titleToNumber(string s)
        {
            int ans = 0;
            for (int  i = 0; i < s.size(); i++)
            {
                auto power = s.size() - (i+1);
                int step = s[i] - 'A' + 1;
                ans += step * pow(26, power);
            }
            return ans;
        }
};
