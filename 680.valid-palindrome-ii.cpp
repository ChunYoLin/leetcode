class Solution
{
    public:
        bool validPalindrome(string s)
        {
            return valid(s, 0, s.size()-1, false);
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
