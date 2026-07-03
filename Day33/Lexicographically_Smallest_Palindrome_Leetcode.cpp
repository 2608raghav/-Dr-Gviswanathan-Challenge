/*
Problem: Lexicographically Smallest Palindrome
Platform: Leetcode
Problem Number: 2697
Topic: String, Two Pointers, Greedy

Approach:
1. Use two pointers:
   - left at the beginning of the string.
   - right at the end of the string.
2. While left < right:
   - If the characters are different,
     replace the larger character with the smaller one.
   - This ensures the palindrome is lexicographically smallest.
3. Move both pointers towards the center.
4. Return the modified palindrome.

Time Complexity: O(n)
- Each character pair is processed exactly once.

Space Complexity: O(1)
- The string is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            char smaller = min(s[left], s[right]);

            s[left] = smaller;
            s[right] = smaller;

            left++;
            right--;
        }

        return s;
    }
};