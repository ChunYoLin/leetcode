class Solution
{
    public:
        enum COLOR
        {
            WHITE,
            GREY,
            BLACK
        };
        std::map<int, std::vector<int>> adj_list;
        std::map<int, COLOR> color;
        vector<int> ans;
        bool isPossible = true;

        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
        {
            for (auto &p : prerequisites)
                adj_list[p.second].push_back(p.first);
            for (int i = 0; i < numCourses; i++)
                color[i] = WHITE;

            for (int i = 0; i < numCourses; i++)
                if (color[i] == WHITE)
                    dfs(i);
            return isPossible ? ans : vector<int>{};
        }

        void dfs(int node)
        {
            if (!isPossible)
                return;

            color[node] = GREY;
            for (auto &adj_node : adj_list[node])
            {
                if (color[adj_node] == WHITE)
                    dfs(adj_node);
                else if (color[adj_node] == GREY)
                    isPossible = false;
            }
            color[node] = BLACK;
            ans.insert(ans.begin(), node);
        }
};
