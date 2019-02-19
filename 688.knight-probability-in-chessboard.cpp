class Solution
{

    public:
        bool in_board(int x, int y, int n)
        {
            if (x >= 0 && y >= 0 && x < n && y < n)
                return true; 
            return false;
        }

        double knightProbability(int N, int K, int r, int c)
        {
            vector<vector<double>> probs(N, vector<double>(N, 0));
            probs[r][c] = 1;
            vector<pair<int, int>> move{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

            for (; K > 0; K--)
            {
                vector<vector<double>> probs2(N, vector<double>(N, 0));
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        for (auto m : move)
                            if (in_board(i+m.first, j+m.second, N))
                                probs2[i+m.first][j+m.second] += (probs[i][j] / 8.0); 
                probs = probs2;
            }

            double ans = 0.;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    ans += probs[i][j];
            return ans;
        }
};
