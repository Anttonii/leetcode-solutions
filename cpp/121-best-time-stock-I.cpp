class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // simple solution
        // time complexity o(n) space complexity o(1)
        int lowest = 10001;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            lowest = min(prices[i], lowest);
            maxProfit = max(maxProfit, prices[i] - lowest);
        }
        return maxProfit;
    }
};