class Solution
{
    public:
        bool validPalindrome(string s)
        {
            return valid(s, false);
        }

        bool valid(string s, bool has_del)
        {
            if (s.size() == 1)
                return true;

            for (int i = 0; i < s.size()/2; i++)
            {
                if (s[i] != s[s.size()-1-i])
                {
                    if (has_del)
                        return false;
                    bool del_left = valid(s.substr(i+1, s.size()-2*i-1), true);
                    bool del_right = valid(s.substr(i, s.size()-2*i-1), true);
                    return del_left | del_right;
                }
            }
            return true;
        }
};
