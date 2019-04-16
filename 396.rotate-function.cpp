class Solution
{
    public:
        int maxRotateFunction(vector<int>& A)
        {
            int cur = 0;
            long sum = 0;
            int n = A.size();
            for (int i = 0; i < A.size(); ++i)
            {
                cur += i*A[i];
                sum += A[i];
            }
            int max = cur;

            for (int i = 1; i < A.size(); ++i)
            {
                cur = cur - (n-1)*(A[n-i]) + sum-A[n-i];
                if (cur > max)
                    max = cur;
            }
            return max;
        }
};
