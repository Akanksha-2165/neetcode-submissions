class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i =0;i < 32; i++)   {
            int bit = n & 1;
            n = n >> 1;

            result = (result << 1) + bit;
        }
        return result;
    }
};

// BRUTE FORCE - Store and reverse the bits
// Extract all 32 bits one by one and store them.
// Then construct the result in reverse order.
// Time Complexity: O(32) = O(1)       Space Complexity: O(32) = O(1)


// OPTIMAL - Build the reversed number using bit manipulation
// Extract the last bit using n & 1.
// Right shift n to process the next bit.
// Left shift result to make space for the new bit,
// then add the extracted bit.
// Repeat exactly 32 times, including leading zeroes.
// Time Complexity: O(32) = O(1)    Space Complexity: O(1)