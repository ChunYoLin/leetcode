class Solution
{
    public:

        int calculate(string s)
        {
            std::stack<int> mystack;
            int num = 0;
            int result = 0;
            int sign = 1;
            for (auto c : s)
            {
                if (isdigit(c))
                    num = num*10 + (c-'0');
                else if (c == '+')
                {
                    result += sign*num; 
                    sign = 1;
                    num = 0;
                }
                else if (c == '-')
                {
                    result += sign*num; 
                    sign = -1;
                    num = 0;
                }
                else if (c == '(')
                {
                    mystack.push(result);
                    mystack.push(sign);
                    result = 0;
                    sign = 1;
                }
                else if (c  == ')')
                {
                    result += sign*num;
                    num = 0;
                    result *= mystack.top();
                    mystack.pop();
                    result += mystack.top();
                    mystack.pop();
                }
            }
            if (num != 0)
                result += sign*num;
            return result;
        }
};
