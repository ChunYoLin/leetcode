class Solution
{
    public:
        int cutOffTree(vector<vector<int>>& forest)
        {
            vector<pair<int, pair<int, int>>> trees;
            for (int i = 0; i < forest.size(); ++i)
                for (int j = 0; j < forest[0].size(); ++j)
                    if (forest[i][j] > 1)
                        trees.push_back({forest[i][j], {i, j}});

            auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) -> bool
            {
                return a.first < b.first;
            };
            sort(trees.begin(), trees.end(), cmp);

            int sr = 0, sc = 0, ans = 0;
            
            for (auto &tree: trees)
            {
                int tr = tree.second.first;
                int tc = tree.second.second;
                int d = dist(forest, sr, sc, tr, tc);
                if (d < 0)
                    return -1;
                sr = tr;
                sc = tc;
                ans += d;
            }
            return ans;
        }

        int dist(vector<vector<int>>& forest, int sr, int sc, int tr, int tc)
        {
            deque<pair<pair<int, int>, int>> q; 
            vector<vector<int>> seen(forest.size(), vector<int>(forest[0].size(), 0));
            q.push_back({{sr, sc}, 0});
            seen[sr][sc] = 1;

            while (!q.empty())
            {
            
                auto top = q.front();
                int r = top.first.first;
                int c = top.first.second;
                int d = top.second;
                if (r == tr && c == tc)
                    return d;
                q.pop_front();
                for (pair<int, int> &t : vector<pair<int, int>>{{r-1, c}, {r, c-1}, {r+1, c}, {r, c+1}})
                {
                    if (t.first < forest.size() && t.first >= 0 &&
                        t.second < forest[0].size() && t.second >= 0 &&
                        seen[t.first][t.second] == 0 &&
                        forest[t.first][t.second])
                    {
                        seen[t.first][t.second] = 1;
                        q.push_back({{t.first, t.second}, d+1});
                    }
                }
            }
            return -1;
        }
};
