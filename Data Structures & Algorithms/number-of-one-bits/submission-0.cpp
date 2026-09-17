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

