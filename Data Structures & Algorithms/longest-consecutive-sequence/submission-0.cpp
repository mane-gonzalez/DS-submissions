class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int current =0;
        int result = 0;

        for(int i =0 ; i < nums.size(); i++) {
            if(set.find(nums[i] - 1) == set.end()) {
                current = 0;

                while(set.find(nums[i] +  current) != set.end()){
                    current++;
                }

                result = max(result, current);
            }
        }
        return result;
    }
};
