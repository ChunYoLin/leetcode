class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int l = 0, r = height.size()-1, area = 0;
            while (l < r)
            {
                int cur_area = (r-l)*min(height[r], height[l]);
                area = max(cur_area, area);
                height[l] < height[r] ? l++ : r--;
            }
            return area;
        }
};
