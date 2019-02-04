class Solution
{
    public:

        int maxWidthRamp(vector<int>& A)
        {
            vector<int> idx(A.size());
            std::iota(idx.begin(), idx.end(), 0);
            std::stable_sort(idx.begin(), idx.end(), [&A](int i, int j) { return A[i] < A[j]; } );

            int ans = 0;
            int min = INT_MAX;
            for (auto &i : idx)
            {
                ans = std::max(ans, i-min);
                if (i < min) 
                    min = i;
            }

            return ans;
        }
};
