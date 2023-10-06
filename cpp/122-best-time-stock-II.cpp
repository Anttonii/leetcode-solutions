class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // linear function that looks ahead if the price tomorrow
        // is better than today or worse and makes selling/buying
        // decision based on that
        //
        // time complexity o(n) space complexity o(1)
        int bought = false;
        int lastBuy = 0;
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++) 
        {
            if(prices[i] <= prices[i + 1]) 
            {
                if (!bought)
                {
                    bought = true;
                    lastBuy = prices[i];
                }
                if (i + 1 == prices.size() - 1)
                    if (bought)
                        profit += prices[i + 1] - lastBuy;
            }
            else
            {
                if(bought)
                {
                    bought = false;
                    profit += prices[i] - lastBuy;
                    lastBuy = 0;
                }
            }
        }

        return profit;
    }
};