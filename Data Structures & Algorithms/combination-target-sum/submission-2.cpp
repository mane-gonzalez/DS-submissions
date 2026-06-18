class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        int index = 0;
        int currSum = 0;

        backtrack(nums, target, index, currSum, curr, result);

        return result;
        
    }

    void backtrack(vector<int> &nums, int target, int index, int currSum, vector<int> &curr, vector<vector<int>> &result){
        if(currSum == target){
            result.push_back(curr);
            return;
        }

        if(index >= nums.size() || currSum > target)
            return;

        curr.push_back(nums[index]);

        backtrack(nums, target, index, currSum + nums[index], curr, result);

        curr.pop_back();

        backtrack(nums, target, index + 1, currSum, curr, result);
    }
};
