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

            while (head <= end)
            {
                if (s[head] != s[end])
                {
                    if (has_del)
                        return false;
                    bool del_left = valid(s, head+1, end, true);
                    bool del_right = valid(s, head, end-1, true);
                    return del_left | del_right;
                }
                head++;
                end--;
            }
            return true;
        }
};
