class Solution
{
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k)
        {
            if (k <= 1)
                return 0;
            int prod = 1;
            int ans = 0, left = 0;
            int len = nums.size();
            for (int right = 0; right < len; ++right)
            {
                prod *= nums[right];        
                while (prod >= k && left <= right)
                    prod /= nums[left++];
                ans += right - left + 1;
            }
            return ans;
        }
};