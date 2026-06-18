class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        backtrack(nums, curr, result);

        return result;        
    }

    void backtrack(vector<int> &nums, vector<int> &curr, vector<vector<int>> &result){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(find(curr.begin(), curr.end(), nums[i]) != curr.end())
                continue;

            curr.push_back(nums[i]);
            backtrack(nums, curr, result);
            curr.pop_back();
        }
    }
};
