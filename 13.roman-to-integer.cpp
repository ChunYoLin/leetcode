class Solution 
{
    public:
        int romanToInt(string s) 
        {
            int ans = 0;
            map<char, int> getint = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
                    ans -= getint[s[i]];
                else if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
                    ans -= getint[s[i]];
                else if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
                    ans -= getint[s[i]];
                else 
                    ans += getint[s[i]];
            }
            return ans;
        }
};
