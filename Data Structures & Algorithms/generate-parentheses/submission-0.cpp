class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        int open = 0;
        int close = 0;
        backtrack(n, open, close, str, result);

        return result;
    }

    void backtrack(int n, int open, int close, string str, vector<string> &result){
        if(open == n && close == n) {
            result.push_back(str);
            return;
        }

        if(open < n)
            backtrack(n, open + 1, close, str + '(', result);

        if(close < open)
            backtrack(n, open, close + 1, str + ')', result);
        
    }
};
