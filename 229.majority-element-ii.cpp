class Solution
{
    public:
        vector<int> majorityElement(vector<int>& nums)
        {
            int candiate0 = 0, candiate1 = 1;
            int count0 = 0, count1 = 0;
            for (auto num: nums)
            {
                if (candiate0 == num)
                    count0 += 1;
                else if (candiate1 == num)
                    count1 += 1;
                else if (count0 == 0)
                {
                    candiate0 = num;
                    count0 = 1;
                }
                else if (count1 == 0)
                {
                    candiate1 = num;
                    count1 = 1;
                }
                else
                {
                    count0 -= 1;
                    count1 -= 1;
                }
            }
            vector<int> ans;
            if (std::count(nums.begin(), nums.end(), candiate0) > nums.size()/3)
                ans.push_back(candiate0);
            if (std::count(nums.begin(), nums.end(), candiate1) > nums.size()/3)
                ans.push_back(candiate1);
            return ans;
        }
};
