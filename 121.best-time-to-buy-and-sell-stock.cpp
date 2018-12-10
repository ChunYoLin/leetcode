class Solution
{
    public:
        int maxProfit(vector<int>& prices)
        {
            if (prices.size() == 0 || prices.size() == 1)
                return 0;
            int profit = 0;
            int min_price = INT_MAX;
            for (int i = 0; i < prices.size(); i++)
            {
                min_price = min(min_price, prices[i]);
                profit = max(profit, prices[i]-min_price);
            }
            return profit;
        }
};
