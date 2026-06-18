class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.size(); right++) {
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);

            result = max(result, (int)set.size());
        }

        return result;
    }
};
