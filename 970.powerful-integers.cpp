class Solution
{
    public:
        vector<int> powerfulIntegers(int x, int y, int bound)
        {
            int i = 0, j = 0;
            if (x > 1)
            {
                while (pow(x, i) < bound)
                    i++;
            }
            if (y > 1)
            {
                while (pow(y, j) < bound)
                    j++;
            }

            vector<int> ans;

            if (x == 1) i = 1;
            if (y == 1) j = 1;
            for (int _i = 0; _i < i; _i++)
                for (int _j = 0; _j < j; _j++)
                {
                    int a = pow(x, _i) + pow(y, _j);
                    if (a <= bound && find(ans.begin(), ans.end(), a) == ans.end())
                        ans.push_back(a);
                }
            return ans;
        }
};
