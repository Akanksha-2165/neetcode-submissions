class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for(auto num : nums) 
        freq[num]++;

    vector<vector<int>> bucket(nums.size()+1);
    for(auto x : freq)  
        bucket[x.second].push_back(x.first);

    vector<int>ans;

    for(int i = bucket.size()-1; i >= 0; i--)   {
        for(int num : bucket[i])    {
            ans.push_back(num);

            if(ans.size() == k)
                return ans;
        }
    }
    return ans;
    }
};

/* 
BRUTE FORCE — SORTING FREQUENCIES
- Count frequencies of all elements using a hash map.
- Convert the frequency map into a vector of pairs (frequency, element) and sort descending.
- Extract the top k elements.
- Time: O(n log n) due to sorting.
- Space: O(n) to store frequencies and pairs.

BETTER — MIN-HEAP (PRIORITY QUEUE)
- Count frequencies using a hash map.
- Maintain a min-heap of size k based on frequencies.
- Push elements into the heap; when size exceeds k, pop the element with the lowest frequency.
- Time: O(n log k) since heap operations are log(k) and k <= n.
- Space: O(n + k) for map and heap storage.

OPTIMAL — BUCKET SORT
- Count element frequencies with a hash map.
- Create an array of buckets where index represents frequency (0 to n).
- Place elements into buckets corresponding to their frequency count.
- Iterate backward from highest frequency bucket to collect top k elements.
- Time: O(n) linear scan and bucket distribution.
- Space: O(n) for frequency map and bucket arrays.
*/