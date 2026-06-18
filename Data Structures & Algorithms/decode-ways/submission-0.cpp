class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if(n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n+1, 0);
        if(s[0] == '0'){
            dp[0] = 0;
        } else {
            dp[0] = 1;
        }

        dp[1] = 1;

        for(int i = 2; i <= n; i++) {

            int oneDig = stoi(s.substr(i-1, 1));
            int twoDig = stoi(s.substr(i-2, 2));

            if(oneDig >= 1){
                dp[i] = dp[i] + dp[i-1];
            }

            if(twoDig >= 10 && twoDig <= 26 ){
                dp[i] = dp[i] + dp[i-2];
            }
        }
        return dp[n];
    }
};
