class Solution
{
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph)
        {
            vector<int> ans;
            vector<int> colors(graph.size(), 0);
            for (int i = 0; i < graph.size(); i++)
                if (graph[i].empty() || dfs(colors, graph, i))
                    ans.push_back(i);
            return ans;
        }

        bool dfs(vector<int>& colors, vector<vector<int>>& graph, int node)
        {
            if (colors[node] != 0)
                return colors[node] == 2;
            colors[node] = 1;
            for (auto &neighboor_node : graph[node])
            {
                if (colors[neighboor_node] == 2)
                    continue;
                if (colors[neighboor_node] == 1 || !dfs(colors, graph, neighboor_node))
                    return false;
            }
            colors[node] = 2;
            return true;
        }
};
