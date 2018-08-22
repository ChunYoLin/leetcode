class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            if (needle.size() == 0)
                return 0;
            int h_ptr = 0, n_ptr = 0, ans = -1;
            while (h_ptr < haystack.size())
            {
                while (h_ptr < haystack.size() && n_ptr < needle.size() && haystack[h_ptr] == needle[n_ptr])
                {
                    if (n_ptr == 0)
                        ans = h_ptr;
                    h_ptr++;
                    n_ptr++;
                }
                if (n_ptr == needle.size())
                    return ans;
                else
                {
                    h_ptr -= n_ptr;
                    n_ptr = 0;
                    ans = -1;
                    h_ptr++;
                }
            }
            return -1;
        }
};
