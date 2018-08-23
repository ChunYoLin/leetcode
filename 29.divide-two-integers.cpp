class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            if (dividend == 0x80000000 && divisor == -1)
                return 0x7fffffff;
            else if (divisor == -1 || divisor == 1)
                return dividend * divisor;
            else if (dividend == divisor)
                return 1;
            int sign = 1-((dividend^divisor)<0)*2;
            int ans = 0;
            if (dividend > 0)
                while ((dividend -= sign*divisor) >= 0)
                    ans += sign;
            else
                while ((dividend -= sign*divisor) <= 0)
                    ans += sign;
            return ans;
        }
};
