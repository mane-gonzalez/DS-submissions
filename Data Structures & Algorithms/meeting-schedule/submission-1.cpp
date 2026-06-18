/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() < 1)
            return true;

        sort(intervals.begin(), intervals.end(),
             [](const Interval& x, const Interval& y) { return x.start < y.start; });

        Interval prev = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            Interval next = intervals[i];

            if(prev.end > next.start) 
                return false;
            else 
                prev = next;
        }
        return true;
    }
};
