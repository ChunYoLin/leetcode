class Solution
{
    public:
        vector<int> countBits(int num)
        {
            vector<int> table(num+1, 0);
            for (int i = 1; i <= num; i++)
                table[i] = (i&1) + table[i/2];
            return table;
        }
};
