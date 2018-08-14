class Solution 
{
    public:
        int threeSumClosest(vector<int>& nums, int target) 
        {
            if (nums.size() <= 3)
                return accumulate(nums.begin(), nums.end(), 0);
            sort(nums.begin(), nums.end());
            int ans = nums[0] + nums[1] + nums[2];
            for (int i = 0; i < nums.size()-2; i++)
            {
                if (i == 0 || (nums[i] != nums[i-1]))
                {
                    int loc2nd = i+1, loc3rd = nums.size()-1;
                    while (loc2nd < loc3rd)
                    {
                        auto sum = nums[i]+nums[loc2nd]+nums[loc3rd];
                        if (abs(target-sum) < abs(target-ans))
                            ans = sum;
                        if (sum < target)
                            loc2nd++;
                        else if (sum > target)
                            loc3rd--;
                        else
                            return target;
                    }
                }
            }
            return ans;

        }
};
