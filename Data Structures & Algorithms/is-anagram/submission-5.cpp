class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> ans(26, 0);

        for(int i=0; i<s.size(); i++)   {
            ans[s[i]-'a']++;   
            ans[t[i]-'a']--;
        }

        return ans == vector<int> (26,0);
    }
};
/*
INTUITION:
- Two strings are anagrams if they contain the same characters with the same frequencies.
- If their lengths differ, they can never be anagrams.

BRUTE
- Sort both strings.
- If the sorted strings are equal, they are anagrams.
- Time: O(n log n)
- Space: O(1) extra if sorting in-place.

BETTER — HASH MAP
- Store the frequency of every character in a hash map for s.
- Decrease the frequency for every character in t.
- If any frequency becomes incorrect, they are not anagrams.
- Time: O(n) average
- Space: O(k), where k is the number of distinct characters.

OPTIMAL — FREQUENCY ARRAY
- Since we only have lowercase English letters, use a fixed
  array of size 26 instead of a hash map.
- Increment for characters in s and decrement for characters in t.
- If all counts are 0, the strings are anagrams.
- Time: O(n)
- Space: O(1)   // fixed 26-size array
*/