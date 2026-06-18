class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        int start = 0;
        int end = start;

        helper(s, start, end, curr, result);
        
        return result;
    }

    void helper(const string &s, int start, int end, vector<string> &curr, vector<vector<string>> &result){
        if(start == s.size()){
            result.push_back(curr);
            return;
        }

        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i)){
                curr.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, end, curr, result);
                curr.pop_back();
            }

        }
    }

    bool isPalindrome(const string &s, int left, int right){
        while(left < right){
            if(!isalnum(s[left])){
                left++;
            } else if(!isalnum(s[right])){
                right--;
            } else if(s[left] != s[right]){
                return false;
            } else {
                left++;
                right--;
            }            
        }
        return true;
    }
};
