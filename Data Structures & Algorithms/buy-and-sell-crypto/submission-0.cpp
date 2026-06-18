class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = prices.size() - 1;

        int buy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size() ; i++) {
            buy = min(buy, prices[i]);
            int sell = prices[i] - buy;

            maxProfit = max(maxProfit, sell);

        }
        return maxProfit; 
    }
};
