class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for(auto interval : intervals)  {
            int currentStart = interval[0];
            int currentEnd = interval[1];

            //either result empty or NO merge
            if(result.empty() || result.back()[1] < currentStart)
                result.push_back(interval);

            //merge
            else 
                result.back()[1] = max(result.back()[1], currentEnd);
            
        }
        return result;
    }
};

// OPTIMAL - Sorting + Linear Scan
// First sort all intervals by their starting point.
// Then traverse the intervals from left to right.

// If the result is empty OR the current interval starts
// after the end of the last interval, there is no overlap,
// so add the current interval directly.
//
// Otherwise, the intervals overlap.
// Merge them by extending the end of the last interval
// to the maximum of both end values.
//
// Time Complexity: O(N log N)     Space Complexity: O(N) for the result array
