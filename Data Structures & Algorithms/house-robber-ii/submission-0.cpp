class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];

        int first = helper(nums, 0, nums.size() - 1);
        int last = helper(nums, 1, nums.size());

        return max(first, last);
        
    }

    int helper(vector<int> &nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i < end; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
