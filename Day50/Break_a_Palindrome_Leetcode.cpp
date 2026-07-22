/*
Problem: Break a Palindrome
Platform: Leetcode
Topic: String, Greedy

Approach:
1. If the palindrome has only one character,
   it is impossible to make it non-palindromic.
   Return an empty string.
2. Traverse only the first half of the palindrome.
3. Find the first character that is not 'a'.
4. Replace it with 'a' and return the string immediately.
   - This produces the lexicographically smallest answer.
5. If every character in the first half is already 'a',
   replace the last character with 'b'.
6. Return the modified string.

Time Complexity: O(n)
- At most half of the string is traversed.

Space Complexity: O(1)
- The string is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();

        if (n == 1)
            return "";

        for (int i = 0; i < n / 2; i++) {

            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[n - 1] = 'b';

        return palindrome;
    }
};