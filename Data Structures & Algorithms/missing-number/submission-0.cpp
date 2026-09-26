class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int xor1=0, xor2=0;

        for(int i = 0; i < n; i++)  {
            xor1 ^= nums[i];
            xor2 ^= i;
        }
        xor2 ^= n;

        return xor1^xor2;
    }
};

/*
Brute Force Approach:
Intuition: Sort the array to match elements with their indices (nums[i] == i). The first index where they don't match is the missing number.
Time Complexity: O(n log n) due to the sorting
Space Complexity: O(1) 

Optimal Math Approach:
Intuition: Compute the theoretical sum of 0 to n using Gauss' formula: n x(n+1)/2.
The difference between this expected total and the actual sum of the array is the missing number.
Time Complexity: O(n) to calculate the actual array sum.Space Complexity: O(1)\

// ALTERNATIVE OPTIMAL - XOR
// XOR all numbers from 0 to n and all elements of nums.
// Equal numbers cancel because x ^ x = 0.
// The only number left is the missing number.
 Time Complexity: O(N)    Space Complexity: O(1)
*/