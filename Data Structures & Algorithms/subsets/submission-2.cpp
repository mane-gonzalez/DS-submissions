class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        int index = 0;

        backtrack(nums, index, curr, result);

        return result;
    }

    void backtrack(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &result){
        result.push_back(curr);

        for(int i = index; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, result);
            curr.pop_back();
        }

        return;
    }
};
