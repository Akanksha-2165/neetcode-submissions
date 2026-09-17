class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1,0);

        for(int i = 1; i<=n; i++)    {
            arr[i]= arr[i & (i-1)]+1;
        }
        return arr;
    }
};

// BRUTE FORCE - Count bits for every number
// For every number from 0 to n, check its binary bits one by one.
// Count how many 1s it contains and store the result.
// Time Complexity: O(N * log N)     Space Complexity: O(N)

// BETTER - Remove rightmost 1 bit
// For every number, use n & (n - 1) to remove its rightmost 1 bit.
// Repeat until the number becomes 0 and count the removed 1s.
// Time Complexity: O(N * log N) in the worst case     Space Complexity: O(N)

// OPTIMAL - Reuse Previous Results
// i & (i - 1) removes one 1-bit from i.
// So the number of 1s in i = number of 1s in (i & (i - 1)) + 1.
// The answer for the smaller number is already stored in arr,
// so we can calculate each answer in O(1).
// Time Complexity: O(N)     Space Complexity: O(N)