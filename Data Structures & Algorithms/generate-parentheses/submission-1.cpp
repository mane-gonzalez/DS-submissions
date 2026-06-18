class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        int open = 0;
        int close = 0;
        backtrack(n, open, close, curr, result);

        return result;
    }

    void backtrack(int n, int open, int close, string curr, vector<string> &result){
        if(open == n && close == n){
            result.push_back(curr);
            return;
        }

        if(open < n)
            backtrack(n, open + 1, close, curr + "(", result);

        if(close < open)
            backtrack(n, open, close + 1, curr + ")", result);
    }
};
