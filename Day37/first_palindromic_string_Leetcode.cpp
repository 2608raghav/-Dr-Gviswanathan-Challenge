/*
Problem: Find First Palindromic String in the Array
Platform: Leetcode
Problem Number: 2108
Topic: String

Approach:
1. Traverse each string in the array.
2. For every string:
   - Use two pointers:
       left = 0
       right = length - 1
   - Compare characters while moving both pointers inward.
   - If any pair differs, the string is not a palindrome.
3. Return the first string that is a palindrome.
4. If no palindrome exists, return an empty string.

Time Complexity: O(n × m)
- n = number of strings.
- m = maximum length of a string.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {

        for (string &word : words) {

            if (isPalindrome(word))
                return word;
        }

        return "";
    }
};