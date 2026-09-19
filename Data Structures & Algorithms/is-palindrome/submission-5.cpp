class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right= s.size()-1;

        while(left<right)   {

            while( left<right && !isalnum(s[left]))
                left++;

            while( left<right && !isalnum(s[right]))
                right--;

            if(tolower(s[left]) != tolower(s[right]) )
                return false;

            right--;
            left++;       
        }
        return true;
    }
};

/*
BRUTE FORCE
- Create a new string containing only alphanumeric characters
  and convert them to lowercase.
- Compare the string with its reverse.
- Time: O(n)
- Space: O(n)

BETTER / OPTIMAL — TWO POINTERS
- Move left and right toward the center.
- Skip non-alphanumeric characters on both sides.
- If the characters differ, return false.
- If all valid characters match, return true.
- Time: O(n)
- Space: O(1)
*/