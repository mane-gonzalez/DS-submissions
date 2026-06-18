class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        vector<int> prev = intervals[0];

        for(int i = 0; i < intervals.size(); i++) {
            vector<int> next = intervals[i];

            if(prev[1] >= next[0]){
                prev[1] = max(prev[1], next[1]);
            } else {
                result.push_back(prev);
                prev = next;
            }
        }

        result.push_back(prev);
        return result;
    }
};
