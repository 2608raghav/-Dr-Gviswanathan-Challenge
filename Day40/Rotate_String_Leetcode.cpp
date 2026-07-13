/*
Problem: Rotate String
Platform: Leetcode
Problem Number: 796
Topic: String

Approach:
1. If the lengths of the two strings are different,
   return false.
2. Concatenate the original string with itself:
      doubled = s + s
3. If goal is a substring of doubled,
   then goal can be obtained by rotating s.
4. Otherwise, return false.

Time Complexity: O(n)
- Concatenation and substring search each take linear time.

Space Complexity: O(n)
- Extra space is used to store the concatenated string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};