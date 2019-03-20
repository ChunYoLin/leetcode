class Solution
{
    public:
        bool isBipartite(vector<vector<int>>& graph)
        {
            vector<bool> visited(graph.size(), false);
            deque<pair<int, int>> queue;
            vector<set<int>> sets(2, set<int> {});
            int i = 0;
            for (int j = 0; j < graph.size(); j++)
            {
                if (visited[i] == false)
                {
                    queue.push_back({i, 0});
                    visited[i] = true;
                    sets[queue.front().second%2].insert(0);
                    while (!queue.empty())
                    {
                        auto cur = queue.front();
                        queue.pop_front();
                        for (auto node : graph[cur.first])
                        {
                            if (sets[cur.second%2].count(node))
                                return false;
                            if (visited[node] == false)
                            {
                                queue.push_back({node, cur.second+1});
                                visited[node] = true;
                                sets[(cur.second+1)%2].insert(node);
                            }
                        }
                    }
                }
                i = j;
            }
            return true;
        }
};
