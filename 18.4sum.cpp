class Solution 
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            if (nums.empty())
                return {};
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                int target_3 = target - nums[i];
                for (int j = i+1; j < nums.size(); j++)
                {
                    int target_2 = target_3 - nums[j];
                    int front = j + 1;
                    int back = nums.size() - 1;
                    while (front < back)
                    {
                        int sum_2 = nums[front] + nums[back];
                        if (sum_2 == target_2)
                        {
                            vector<int> quadruplet(4, 0);
                            quadruplet[0] = nums[i];
                            quadruplet[1] = nums[j];
                            quadruplet[2] = nums[front];
                            quadruplet[3] = nums[back];
                            ans.push_back(quadruplet);
                            while ((front < back) && (nums[front] == quadruplet[2])) front++;
                            while ((front < back) && (nums[back] == quadruplet[3])) back--;
                        }
                        else if (sum_2 < target_2)
                            front++;
                        else if (sum_2 > target_2)
                            back--;
                    }
                    while ((j+1 < nums.size()) && (nums[j+1] == nums[j]))++j;
                }
                while ((i+1 < nums.size()) && (nums[i+1] == nums[i]))++i;
            }
            return ans;
        }
};
