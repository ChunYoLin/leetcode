class Solution
{
    public:
        void nextPermutation(vector<int>& nums)
        {
            int k = nums.size() - 2;
            while (k >= 0 && nums[k] >= nums[k + 1])
                --k;
            if (k < 0)
                return std::reverse(nums.begin(), nums.end());
            else
            {
                int l = nums.size() - 1;
                for (; l > k; --l)
                    if (nums[l] > nums[k])
                        break;
                swap(nums[k], nums[l]);
                std::reverse(nums.begin() + k + 1, nums.end());
            }
        }
};
