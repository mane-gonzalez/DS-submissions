class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // State: can buy
            dp[i][1] = max(-prices[i] + dp[i + 1][0],   // buy today
                           dp[i + 1][1]);                // skip today

            // State: can sell
            dp[i][0] = max(prices[i] + dp[i + 2][1],    // sell today
                           dp[i + 1][0]);                // skip today
        }

        return dp[0][1];
    }
};