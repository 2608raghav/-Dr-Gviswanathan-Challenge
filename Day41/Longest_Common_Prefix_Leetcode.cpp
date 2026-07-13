/*
Problem: Longest Common Prefix
Platform: Leetcode
Problem Number: 14
Topic: String

Approach:
1. Assume the first string is the common prefix.
2. Traverse the remaining strings one by one.
3. For each string:
   - Compare it with the current prefix character by character.
   - Determine the length of the common prefix.
   - Update the prefix to this common portion.
4. If the prefix becomes empty, return an empty string.
5. After processing all strings, return the final prefix.

Time Complexity: O(n × m)
- n = number of strings.
- m = length of the shortest string.

Space Complexity: O(1)
- No extra space is used apart from the prefix string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            int j = 0;

            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
                return "";
        }

        return prefix;
    }
};