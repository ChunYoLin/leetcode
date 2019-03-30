class Solution
{
    public:
        vector<int> powerfulIntegers(int x, int y, int bound)
        {
            vector<int> x_list{1};
            vector<int> y_list{1};
            if (x > 1)
            {
                x_list.push_back(x);
                int _x = x;
                while (_x < bound)
                {
                    _x *= x;
                    x_list.push_back(_x);
                }
            }

            if (y > 1)
            {
                y_list.push_back(y);
                int _y = y;
                while (_y < bound)
                {
                    _y *= y;
                    y_list.push_back(_y);
                }
            }

            vector<int> ans;
            for (auto x : x_list)
                for (auto y : y_list)
                    if (x+y <= bound && find(ans.begin(), ans.end(), x+y) == ans.end())
                        ans.push_back(x+y);
            return ans;
        }
};
