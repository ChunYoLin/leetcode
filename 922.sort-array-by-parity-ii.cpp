class Solution
{
    public:
        vector<int> sortArrayByParityII(vector<int>& A)
        {
            vector<int> ans(A.size(), 0);
            int odd = 1, even = 0;
            for (auto &a : A)
            {
                if (a%2 == 0)
                {
                    ans[even] = a;
                    even += 2;
                }
                else if (a%2 == 1)
                {
                    ans[odd] = a;
                    odd += 2;
                }
            }
            return ans;
        }
};
