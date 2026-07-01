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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        int maxend = 0, minstart = INT_MAX;
        for(Interval& i : intervals)
        {
            maxend = max(maxend, i.end);
            minstart = min(minstart, i.start);
        }
        vector<int> line(maxend-minstart + 1, 0);
        for(Interval& i : intervals)
        {
            line[i.start-minstart]++;
            line[i.end-minstart]--;
        }
        int currmax = 0;
        int curr = 0;
        for(int i : line)
        {
            curr+=i;
            currmax = max(currmax, curr);
        }
        return currmax;
    }
};
