class Solution 
{
    public:
        int myAtoi(string str) 
        {
            std::reverse(str.begin(), str.end());
            int ans = 0;
            int k = 0;
            bool pre_is_num;
            bool overflow = false;
            for (auto &c : str)
            {
                int c_i = c-'0';
                if (c_i >= 0 && c_i <= 9)
                {
                    if (!pre_is_num)
                    {
                        ans = 0;
                        k = 0;
                    } 
                    int pre_ans = ans;
                    ans += c_i*pow(10, k);
                    k += 1;
                    if (pre_ans >= 0 && ans < 0)
                    {
                        ans = 0x7fffffff;
                        overflow = true;
                    }
                    pre_is_num = true;
                }
                else
                {
                    if (c != ' ')
                    {
                        if (!pre_is_num)
                        {
                            ans = 0;
                            k = 0;
                        } 
                        else
                        {
                            if (c == '-')
                            {
                                if (overflow)
                                    ans = 0x80000000;
                                else
                                    ans *= -1;
                            }
                            else if (c == '+')
                                ans *= 1;
                            else 
                            {
                                ans = 0;
                                k = 0;
                            }
                        }
                    }
                    pre_is_num = false;
                }
            }
            return ans;
        }
};
