/*
Problem: Roman to Integer
Platform: LeetCode
Problem Number: 13
Topic: Hash Map, String, Math

Approach:
1. Store the value of every Roman numeral:
      I -> 1
      V -> 5
      X -> 10
      L -> 50
      C -> 100
      D -> 500
      M -> 1000

2. Traverse the string from left to right.

3. Compare the current Roman numeral with the next one:
   - If the current value is smaller than the next value,
     subtract the current value.
   - Otherwise, add the current value.

4. Add the value of the last character because it has no
   character after it.

Example:
MCMXCIV

M = 1000       -> Add
C < M          -> Subtract 100
M = 1000       -> Add
X < C          -> Subtract 10
C = 100        -> Add
I < V          -> Subtract 1
V = 5          -> Add

Result = 1994

Time Complexity: O(n)
- We traverse the string once.

Space Complexity: O(1)
- The Roman numeral mapping has a fixed number of characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;

        for (int i = 0; i < s.size() - 1; i++) {

            
            if (mp[s[i]] < mp[s[i + 1]]) {
                res -= mp[s[i]];
            }
            else {
                res += mp[s[i]];
            }
        }

        
        res += mp[s.back()];

        return res;
    }
};

