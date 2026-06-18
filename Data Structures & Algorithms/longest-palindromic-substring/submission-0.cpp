class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2)
            return s;

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < n; i++){
            expandFromCenter(s, i, i, start, maxLen);
            expandFromCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

    void expandFromCenter(string s, int left, int right, int &start, int &maxLen){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        int len = right - left - 1;

        if(len > maxLen){
            maxLen = len;
            start = left + 1;
        }

        return;
    }
};
