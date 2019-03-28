class Solution
{
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper)
        {
            vector<long> sums(nums.size()+1, 0);
            for (int i = 1; i < sums.size(); i++)
                sums[i] = sums[i-1] + nums[i-1];
            return mergeCount(sums, lower, upper, 0, nums.size()+1);
        }

        int mergeCount(vector<long>& sums, int lower, int upper, int start, int end)
        {
            if ((end - start) <= 1)
                return 0;
            int mid = (start+end) / 2;
            int count = mergeCount(sums, lower, upper, start, mid) + mergeCount(sums, lower, upper, mid, end);

            int j = mid;
            int k = mid;
            for (int i = start; i < mid; i++)
            {
                while (j < end && sums[j] - sums[i] < lower)
                    j++;
                while (k < end && sums[k] - sums[i] <= upper)
                    k++;
                count += k-j;
            }
            vector<long> left(sums.begin()+start, sums.begin()+mid);
            left.push_back(LONG_MAX);
            vector<long> right(sums.begin()+mid, sums.begin()+end);
            right.push_back(LONG_MAX);
            int l = 0, r = 0, s = start;
            while (s < end)
            {
                if (left[l] > right[r])
                    sums[s++] = right[r++]; 
                else if (left[l] <= right[r])
                    sums[s++] = left[l++]; 
            }
            return count;
        }
};
