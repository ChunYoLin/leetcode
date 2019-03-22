class Solution
{
    public:
        int bestRotation(vector<int>& A)
        {
            vector<int> pointLoss(A.size(), 0);
            for (int i = 0; i < A.size(); i++) 
                pointLoss[(i-A[i]+A.size()+1) % A.size()]++;

            vector<int> score(A.size(), 0);
            int max = score[0];
            int max_k = 0;
            for (int k = 1; k < A.size(); k++)
            {
                score[k] = score[k-1] - pointLoss[k] + 1;
                if (score[k] > max)
                {
                    max = score[k];
                    max_k = k;
                }
            }
            return max_k;
        }
};
