class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [] (vector<int> &a, vector<int> &b)  {
                return a[1]<b[1];
            });

        int count = 0;
        int lastEnd =  intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)   {
            // No overlap → keep current interval
            if(intervals[i][0] >= lastEnd)  
                lastEnd = intervals[i][1];

            //overlap → remove current interval
            else
                count++;
        }
        return count;
    }
};

// BRUTE FORCE - Try all possibilities
// For every interval, we can either keep it or remove it.
// Try all possible combinations and find the minimum removals
// needed to make the remaining intervals non-overlapping.
// Time Complexity: O(2^N)      Space Complexity: O(N) for recursion

// BETTER - Dynamic Programming
// Sort the intervals and use DP to find the maximum number
// of non-overlapping intervals that can be kept.
// At each interval, choose between keeping it or skipping it.
// Time Complexity: O(N^2)      Space Complexity: O(N)

// OPTIMAL - Greedy
// Sort intervals by their END time.
// Keep the interval that ends earliest because it leaves
// the maximum possible space for future intervals.
// If current.start >= lastEnd, there is no overlap,
// so keep the current interval and update lastEnd.
// Otherwise, the intervals overlap, so remove the current
// interval. We do NOT update lastEnd because the previous
// interval ends earlier and is the better one to keep.
// Time Complexity: O(N log N) due to sorting     Space Complexity: O(1) extra space
