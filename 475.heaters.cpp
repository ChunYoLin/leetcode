#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters)
        {
            if (houses.empty())
                return 0;
            int radius = 0;
            sort(heaters.begin(), heaters.end());
            for (auto &house : houses)
            {
                int distance = -1;
                for (auto &heater : heaters)
                {
                    int dis = abs(heater-house);
                    if (distance == -1)
                        distance = dis;
                    else if (distance >= dis)
                        distance = dis;
                    else
                        break;
                }
                radius = max(radius, distance);
            }
            return radius;
        }
};
