class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0)   {
            int sum = a ^ b;
            int carry = (a & b) << 1;

            a = sum;
            b = carry;
        }
        return a;
    }
};

// OPTIMAL - Bit Manipulation
// XOR (a ^ b) gives the sum without carry.
// AND (a & b) finds where the carry is generated,
// and left shift moves the carry to the correct position.
// Repeat until there is no carry left.
// Time Complexity: O(1) for fixed-size integers       Space Complexity: O(1)