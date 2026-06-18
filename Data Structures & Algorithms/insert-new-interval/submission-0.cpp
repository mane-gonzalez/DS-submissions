class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int n = intervals.size();

        int left = 0;

        while (left < n && intervals[left][1] < newInterval[0]){
            result.push_back(intervals[left]);
            left++;
        }

        while(left < n && intervals[left][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[left][0], newInterval[0]);
            newInterval[1] = max(intervals[left][1], newInterval[1]);
            left++;
        }

        result.push_back(newInterval);

        while(left < n){
            result.push_back(intervals[left]);
            left++;
        }

        return result;
    }
};
