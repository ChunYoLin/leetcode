class Solution
{
    public:
        int maxRotateFunction(vector<int>& A)
        {
            int cur = 0;
            long sum = 0;
            for (int i = 0; i < A.size(); ++i)
            {
                cur += i*A[i];
                sum += A[i];
            }
            int max = cur;

            for (int i = 1; i < A.size(); ++i)
            {
                cur = cur - (A.size()-1)*(A[A.size()-i]) + sum-A[A.size()-i];
                if (cur > max)
                    max = cur;
            }
            return max;
        }
};
