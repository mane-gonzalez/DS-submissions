class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;

        for(auto str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for(auto elem:map) {
            result.push_back(elem.second);
        }

        return result;
    }
};
