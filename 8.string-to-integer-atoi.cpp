class Solution 
{
    public:
        int myAtoi(string str) 
        {
            vector<int> ans;
            for (auto &c : str)
            {
                int c_i = c - '0';
                if (c_i >= 0 && c_i <= 9)
                {
                    if (ans.empty())
                        ans.push_back(1);
                    ans.push_back(c_i);
                }
                else
                {
                    if (!ans.empty())
                        break;
                    else
                    {
                        if (c == '+')
                            ans.push_back(1); 
                        else if (c == '-')
                            ans.push_back(-1);
                        else if (c != ' ')
                            break;
                    }
                }
            }
            if (ans.size() > 1)
            {
                int result = 0;
                int sign = ans[0];
                for (int i = 1; i < ans.size(); i++)
                {
                    if (sign > 0)
                    {
                        int pre_result = result;
                        result += ans[i]*pow(10, ans.size()-i-1);
                        if (result < pre_result)
                            result = 0x7fffffff;
                    }
                    else
                        result -= ans[i]*pow(10, ans.size()-i-1);
                }
                return result;
            }
            else
                return 0;
        }
};
