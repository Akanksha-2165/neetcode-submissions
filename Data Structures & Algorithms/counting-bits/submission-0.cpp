class Solution {
public:

    int count_ones(int n)  {
        int cnt = 0;
        while(n)    {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> arr;

        for(int i = 0; i <= n; i++)
            arr.push_back(count_ones(i));

        return arr;
    }
};
