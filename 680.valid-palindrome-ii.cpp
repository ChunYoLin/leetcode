class Solution
{
    public:
        bool validPalindrome(string s)
        {
            for (int i = 0, j = s.size() - 1; i < j; i++, j--)
                if (s[i] != s[j])
                {
                    int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                    while (i1 < j1 && s[i1] == s[j1])
                    {
                        i1++;
                        j1--;
                    };
                    while (i2 < j2 && s[i2] == s[j2])
                    {
                        i2++;
                        j2--;
                    };
                    return i1 >= j1 || i2 >= j2;
                }
            return true;
        }

        bool valid(const string& s, int head, int end, bool has_del)
        {
            if (head == end)
                return true;

            while (s[head] == s[end])
            {
                head++;
                end--;
                if (head > end)
                    return true;
            }

            if (s[head] != s[end])
                return !has_del && (valid(s, head+1, end, true) | valid(s, head, end-1, true));
            return true;
        }
};
