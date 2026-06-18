class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int result = 0;

        vector<int> prev = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            vector<int> next = intervals[i];

            if(next[0] < prev[1]){
                result++;
            } else {
                prev = next;
            }
        }
        return result;
    }
};
