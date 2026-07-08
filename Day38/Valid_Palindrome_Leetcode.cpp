/*
Problem: Valid Palindrome
Platform: Leetcode
Problem Number: 125
Topic: String, Two Pointers

Approach:
1. Use two pointers:
   - left starting from the beginning.
   - right starting from the end.
2. Ignore all non-alphanumeric characters by moving the pointers.
3. Compare the lowercase versions of the current characters.
4. If they are different, return false.
5. Otherwise, move both pointers inward.
6. Continue until the pointers meet or cross.
7. If no mismatch is found, return true.

Time Complexity: O(n)
- Each character is visited at most once.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};