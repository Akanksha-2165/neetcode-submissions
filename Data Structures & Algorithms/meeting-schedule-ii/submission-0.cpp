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
        if(intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
        [](const Interval &a ,const Interval &b)    {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i = 0;i < intervals.size(); i++)    {

            if(!min_heap.empty() && min_heap.top() <= intervals[i].start)
                min_heap.pop();

            min_heap.push(intervals[i].end);
        }   
        return min_heap.size();
    }
};

// BRUTE FORCE - Count Overlapping Meetings
// Check every meeting's start time and count active meetings.
// Maximum overlap = minimum rooms required.
// Time Complexity: O(N^2)  Space Complexity: O(1) extra space

// BETTER - Sorting + Two Pointers
// Sort start and end times separately.
// Track active meetings and update the maximum room count.
// Time Complexity: O(N log N)  Space Complexity: O(N)

// OPTIMAL - Sorting + Min-Heap
// Sort meetings by start time and store room end times in a min-heap.
// Reuse the earliest room if its end time <= current start; otherwise allocate another.
// Time Complexity: O(N log N)  Space Complexity: O(N)