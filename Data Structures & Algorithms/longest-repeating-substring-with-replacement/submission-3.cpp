class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;

        int left = 0;
        int result = 0;
        int charLength = 0;

        for(int right = 0; right < s.size(); right++) {
            map[s[right]]++;

            charLength = max(charLength, map[s[right]]);

            if((right - left + 1) - charLength > k) {
                map[s[left]]--;
                left++;
            }

            result = max(result , (right - left + 1));
        }
        return result;
    }
};
