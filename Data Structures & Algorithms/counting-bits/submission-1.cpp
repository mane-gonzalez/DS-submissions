class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        vector<int> result;

        dp[0] = 0;
        result.push_back(dp[0]);
        
        for(int i = 1; i <=n; i++) {
            dp[i] = dp[i&(i-1)] + 1;
            result.push_back(dp[i]);
        }

        return result;
    }
};
