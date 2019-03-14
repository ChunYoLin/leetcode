class Solution
{
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
        {
            unordered_map<int, std::vector<int>> adj_list;
            map<int, int> in_degree;
            for (auto &p : prerequisites)
            {
                adj_list[p.second].push_back(p.first);
                in_degree[p.first] += 1;
            }

            deque<int> queue;
            vector<int> ans;
            for (int i = 0; i < numCourses; i++)
                if (in_degree[i] == 0)
                    queue.push_back(i);
            while (!queue.empty())
            {
                auto node = queue.front();
                queue.pop_front(); 
                for (auto &adj_node : adj_list[node])
                {
                    in_degree[adj_node]--;
                    if (in_degree[adj_node] == 0)
                        queue.push_back(adj_node);
                }
                ans.push_back(node);
            }
            return ans.size() == numCourses ? ans : vector<int>{};
        }
};
