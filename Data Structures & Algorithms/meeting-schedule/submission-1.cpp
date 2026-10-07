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
        sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        int lastEnd = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++)   {

            //non overlapping
            if(intervals[i].start >= lastEnd)
                lastEnd = intervals[i].end;
            //overlapping
            else
                return false;
        }
        return true;
    }
};

// OPTIMAL - Sorting + Linear Scan
// Sort all meetings by their start time.
// Then compare each meeting with the previous meeting.
// If current.start < previous.end, the two meetings overlap,
// so the person cannot attend all meetings.
// If current.start >= previous.end, there is no conflict.
// Equal values are allowed because a meeting ending at the
// same time another one starts is NOT considered a conflict.
// Time Complexity: O(N log N) due to sorting     Space Complexity: O(1) extra space
