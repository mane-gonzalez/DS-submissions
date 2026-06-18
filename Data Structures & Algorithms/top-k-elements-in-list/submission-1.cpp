class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<vector<int>> bucket(nums.size() + 1 );
        vector<int> result;

        for(auto num:nums){
            map[num]++;
        }

        for(auto elem:map){
            bucket[elem.second].push_back(elem.first);
        }

        for(int i = nums.size(); i >=0; i--) {
            if(k <= result.size())
                return result;

            result.insert(result.begin(), bucket[i].begin(), bucket[i].end());    
        }
        return {};
    }
};
