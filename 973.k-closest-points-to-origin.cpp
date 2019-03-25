class Solution
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
        {
            auto compare = [](const vector<int>& p1, const vector<int>& p2) -> bool
            {
                return (pow(p1[0], 2)+pow(p1[1], 2)) < (pow(p2[0], 2)+pow(p2[1], 2));
            };
            sort(points.begin(), points.end(), compare);
            vector<vector<int>> ans;
            for (auto point = points.begin(); K > 0; point++, K--)
                ans.push_back(*point);
            return ans;
        }
};
