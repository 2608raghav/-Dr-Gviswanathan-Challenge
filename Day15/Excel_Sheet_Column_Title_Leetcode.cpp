/*
Problem: Excel Sheet Column Title
Platform: Leetcode
Problem Number: 168
Topic: Math, String

Approach:
1. Excel columns follow a 1-based numbering system:
      A -> 1
      B -> 2
      ...
      Z -> 26
      AA -> 27
2. Since there is no digit '0' in this system, decrement the column number by 1
   before processing each digit.
3. Repeatedly:
   - Decrement columnNumber by 1.
   - Compute the current character:
         ('A' + columnNumber % 26)
   - Append it to the result.
   - Divide columnNumber by 26.
4. The characters are generated in reverse order, so reverse the string.
5. Return the resulting column title.

Time Complexity: O(log26(n))
- One iteration for each base-26 digit.

Space Complexity: O(1)
- Ignoring the output string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
         string ans;

        while (columnNumber) {
            columnNumber--;
     
            ans = ans + (char)((columnNumber) % 26 + 'A');
            columnNumber = (columnNumber) / 26;
        }

        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};