class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int buy = prices[0];
        int maxProfit = 0;

        for(int right = 1; right < prices.size(); right++){
            buy = min(buy, prices[right]);
            int profit = prices[right] - buy;

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
