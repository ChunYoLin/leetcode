class Solution
{
    public:
        vector<int> sortArrayByParityII(vector<int>& A)
        {
            int odd = 1;
            for (int even = 0; even < A.size(); even+=2)
            {
                if (A[even]%2 == 1)
                {
                    while (A[odd]%2 == 1)
                        odd += 2;
                    swap(A[even], A[odd]);
                    odd += 2;
                }
            }
            return A;
        }
};
