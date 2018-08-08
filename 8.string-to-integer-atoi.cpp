class Solution 
{
    public:
        int myAtoi(string str) 
        {
            int i = 0;
            while (str[i] == ' ') 
                i++;
            int sign = 1;
            if (str[i] == '-' || str[i] == '+')
                sign = 1 - 2*(str[i++] == '-');
            if (str[i] <= '0' && str[i] >= '9')
                return 0;
            vector<int> ans;
            while (str[i] >= '0' && str[i] <= '9')
                ans.push_back(str[i++]-'0');
            int result = 0;
            if (ans.size() > 0)
            {
                for (int i = 0; i < ans.size(); i++)
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
