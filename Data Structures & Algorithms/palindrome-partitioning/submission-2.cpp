class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        string str = "";
        
        int index = 0;
        helper(s,  index, str, curr, result);

        return result;
    }

    void helper(const string &s, int index, string str, vector<string> &curr, vector<vector<string>> &result) {
        if(index == s.size()){
            result.push_back(curr);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                helper(s, i + 1, str, curr, result);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right){
        while (left < right) {
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
