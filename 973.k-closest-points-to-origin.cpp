class Solution
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
        {
            vector<int> distances;
            for (auto point : points)
            {
                int distance = pow(point[0], 2) + pow(point[1], 2);
                distances.push_back(distance);
            }
            sort(distances.begin(), distances.end());
            int distance = distances[K-1];

            vector<vector<int>> ans;
            for (auto point = points.begin(); point != points.end(); point++)
            {
                if (pow((*point)[0], 2) + pow((*point)[1], 2) <= distance)
                {
                    ans.push_back(*point);
                    if (ans.size() == K)
                        break;
                }
            }
            return ans;
        }
};
