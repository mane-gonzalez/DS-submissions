class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        int currSum = 0;
        int index = 0;

        backtrack(nums, index, target, currSum, curr, result);
        return result;
        
    }

    void backtrack(vector<int> &nums, int index, int target, int currSum, vector<int> &curr, vector<vector<int>> &result){
        if(currSum == target) {
            result.push_back(curr);
            return;
        }
        if(currSum > target || index == nums.size()) return;

        curr.push_back(nums[index]);

        backtrack(nums, index, target, nums[index] + currSum, curr, result);

        curr.pop_back();
        backtrack(nums, index + 1, target, currSum, curr, result);
    }
};
