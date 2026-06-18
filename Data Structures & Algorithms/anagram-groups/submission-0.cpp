class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto word:strs) {
            vector<int> freq(26,0);

            for(auto c:word) {
                freq[c - 'a']++;
            }

            string key;

            for(int val:freq) {
                key += "," + to_string(val);
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        for(auto pair:mp) {
            result.push_back(pair.second);
        }
        return result;
    }
};
