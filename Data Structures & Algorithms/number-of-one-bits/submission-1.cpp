class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n)    {   
            n = n & (n-1);   // loop will runs only the no. of 1's present times 
            cnt++;
        }
        return cnt;
    }
};

// BRUTE FORCE - Check all 32 bits
// Check each bit position one by one using (1 << i).
// If the bit is 1, increment the count.
// Time Complexity: O(32) = O(1)     Space Complexity: O(1)

// BETTER - Right Shift
// Check the last bit using (n & 1).
// If it is 1, increment the count.
// Right shift n by 1 to move to the next bit.
// Repeat until all bits are checked.
// Time Complexity: O(32) = O(1)     Space Complexity: O(1)

// OPTIMAL - Remove the Rightmost 1 Bit
// n & (n - 1) removes the rightmost 1 bit from n.
// So the loop runs only once for every 1 bit in the number.
// Increment the count after removing each 1 bit.
// Time Complexity: O(K), where K = number of 1 bits     Space Complexity: O(1)