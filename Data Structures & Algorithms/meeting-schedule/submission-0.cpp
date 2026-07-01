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
        auto cmp = [] (Interval& a, Interval& b) {
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int prev = 0;
        for(Interval i : intervals)
        {
            if(i.start < prev) return false;
            prev = i.end;
        }
        return true;
    }
};
