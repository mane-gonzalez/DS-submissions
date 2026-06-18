class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int left = 0;
        int maxLength = 0;
        int maxCharLength = 0;

        for(int right = 0; right < s.size(); right++){
            map[s[right]]++;

            maxCharLength = max(maxCharLength, map[s[right]]);

            if((right - left + 1) - (maxCharLength) > k) {
                map[s[left]]--;
                left++;
            } 

            maxLength = max(maxLength, (right-left + 1));
        }

        return maxLength;
    }
};