class Solution
{
    public:
        int search(vector<int>& nums, int target)
        {
            if (nums.size() == 0)
                return -1;
            int start = 0;
            int end = nums.size()-1;
            while (start < end-1)
            {
                int mid = (end+start) / 2;
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    start = mid;
                else if (nums[mid] > target)
                    end = mid;
            }
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            return -1;
        }
};
