class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        while(i < n && intervals[i][1] < newinterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newinterval[1])    {
            newinterval[0] = min(intervals[i][0], newinterval[0]);
            newinterval[1] = max(intervals[i][1], newinterval[1]);
            i++;
        }

        result.push_back(newinterval);

        while(i < n)    {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

// OPTIMAL - Linear Scan
// Traverse intervals from left to right.
// 1. Intervals completely before newInterval → add directly.
// 2. Intervals completely after newInterval → add newInterval, then remaining intervals.
// 3. Overlapping intervals → merge by taking min start and max end.
// Time Complexity: O(N)    Space Complexity: O(N) for the output array
