/*
Problem: Valid Parenthesis String
Platform: Leetcode
Problem Number: 678
Topic: String, Stack, Greedy

Approach:
1. Maintain two counters:
   - low  = minimum possible number of open parentheses.
   - high = maximum possible number of open parentheses.
2. Traverse the string character by character.
3. For '(':
   - Increment both low and high.
4. For ')':
   - Decrement both low and high.
5. For '*':
   - It can act as:
       '('  -> increase open count
       ')'  -> decrease open count
       ''   -> ignore
   - Therefore:
       low--
       high++
6. If high becomes negative:
   - There are too many closing brackets.
   - Return false.
7. Keep low non-negative:
      low = max(low, 0)
8. After processing all characters:
   - If low == 0, a valid assignment exists.
   - Otherwise, return false.

Time Complexity: O(n)
- Single traversal of the string.

Space Complexity: O(1)
- Only two counters are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }

            if(high < 0) {
                return false;
            }

            low = max(low, 0);
        }

        return low == 0;
    }
};