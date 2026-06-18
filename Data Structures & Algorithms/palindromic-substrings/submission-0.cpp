class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        if(n < 2)
            return 1;

        int start = 0;
        int maxLen = 1;
        int result = 0;

        for(int i = 0; i < n; i++){
            startFromCenter(s, i, i, start, maxLen, result);
            startFromCenter(s, i, i + 1, start, maxLen, result);
        }

        return result;
    }

    void startFromCenter(string s, int left, int right, int &start, int &maxLen, int &result){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            result++;
        }

        int len = right - left - 1;

        if(len > maxLen){
            maxLen = len;
            start = left + 1;
        }
        return;
    }
};
