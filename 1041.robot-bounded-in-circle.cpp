class Solution
{
    public:
        bool isRobotBounded(string instructions)
        {
            vector<pair<int, int>> d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            int x = 0, y = 0, i = 0;

            for (auto &c : instructions)
            {
                if (c == 'R')
                    i = (i + 1) % 4;
                else if (c == 'L')
                    i = (i + 3) % 4;
                else
                {
                    x += d[i].first;
                    y += d[i].second;
                }
            }
            return x == 0 && y == 0 || i > 0;
        }
};
