/*
Problem: Number of Segments in a String
Platform: Leetcode
Problem Number: 434
Topic: String

Approach:
1. Traverse the string from left to right.
2. A new segment starts when:
   - The current character is not a space, and
   - It is either the first character of the string or the previous
     character is a space.
3. Count every such occurrence.
4. Return the total number of segments.

Time Complexity: O(n)
- The string is traversed exactly once.

Space Complexity: O(1)
- Only a counter is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {

        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                count++;
            }
        }

        return count;
    }
};