class Solution
{
    public:
        int minKBitFlips(vector<int>& A, int K)
        {
            bool flip = false;
            int ans = 0;
            vector<bool> hint(A.size(), false);

            for (int i = 0; i < A.size(); i++)
            {
                flip ^= hint[i];
                if (A[i] ^ flip == 0)
                {
                    flip ^= true;
                    ans += 1;
                    if (i+K > A.size())
                        return -1;
                    if (i+K < A.size())
                        hint[i+K] = hint[i+K] ^ true;
                }
            }
            return ans;
        }
};
