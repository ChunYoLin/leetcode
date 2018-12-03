class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            int a = 0, b = 0;
            for (auto &num : nums)
            {
                b = b ^ num & ~a;
                a = a ^ num & ~b;
            }
            return a | b;
        }
};
