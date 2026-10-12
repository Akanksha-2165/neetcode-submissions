class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for(int i=0; i<nums.size(); i++)    {
            if(seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};


/*
BRUTE FORCE
- Compare every pair of elements to check for duplicates.
- Time: O(n²)
- Space: O(1)

BETTER
- Sort the array first.
- After sorting, duplicates will be adjacent.
- Check consecutive elements for equality.
- Time: O(n log n)
- Space: O(1) if sorting in-place.

OPTIMAL — HASH SET
- Store every element we have already seen in an unordered_set.
- If an element is already present, a duplicate exists.
- Otherwise, insert it and continue.
- Time: O(n) average
- Space: O(n)
*/