class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        int currSum = 0;
        int index = 0;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, index, currSum, curr, result);

        return result;
    }

    void backtrack(vector<int> &candidates, int target, int index, int currSum, vector<int> &curr, vector<vector<int>> &result){
        if(currSum == target){
            result.push_back(curr);
            return;
        }

        if(index >= candidates.size() || currSum > target)
        return;

        for(int i = index; i< candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1])
                continue;
            
            curr.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, currSum + candidates[i], curr, result);
            curr.pop_back();
        }
    }
};
