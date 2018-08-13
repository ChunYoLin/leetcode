class Solution 
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            if(nums.size()<=2) return {};
            int target = 0;
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            for (int i = 0; i < nums.size()-2; i++)
            {
                if (i == 0 || (nums[i] != nums[i-1]))
                {
                    int loc2nd = i+1, loc3rd = nums.size()-1;
                    while (loc2nd < loc3rd)
                    {
                        auto sum = nums[i]+nums[loc2nd]+nums[loc3rd];
                        if (sum == target)
                        {
                            vector<int> triple{nums[i], nums[loc2nd], nums[loc3rd]};
                            ans.push_back(triple);
                            while (loc2nd < loc3rd && nums[loc2nd] == nums[loc2nd+1])loc2nd++;
                            while (loc2nd < loc3rd && nums[loc3rd] == nums[loc3rd-1])loc3rd--;
                            loc2nd++;
                            loc3rd--;
                        }
                        else if (sum < target)
                            loc2nd++;
                        else if (sum > target)
                            loc3rd--;
                    }
                }
            }
            return ans;
        }
};
