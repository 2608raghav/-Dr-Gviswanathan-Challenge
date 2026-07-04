/*
Problem: Length of Last Word
Platform: Leetcode
Problem Number: 58
Topic: String

Approach:
1. Start from the end of the string.
2. Skip all trailing spaces.
3. Count the characters until:
   - The beginning of the string is reached, or
   - Another space is encountered.
4. Return the count as the length of the last word.

Time Complexity: O(n)
- At most one traversal of the string.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};