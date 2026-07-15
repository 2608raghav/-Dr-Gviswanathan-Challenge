/*
Problem: Zigzag Conversion
Platform: Leetcode
Problem Number: 6
Topic: String, Simulation

Approach:
1. If numRows is 1 or greater than or equal to the string length,
   return the original string.
2. Create a vector of strings, where each string represents one row
   of the zigzag pattern.
3. Traverse the input string while maintaining:
   - currentRow
   - direction (moving down or up)
4. Append each character to its corresponding row.
5. Change the direction:
   - At the first row, start moving downward.
   - At the last row, start moving upward.
6. After processing all characters, concatenate all rows.
7. Return the resulting string.

Time Complexity: O(n)
- Each character is processed exactly once.

Space Complexity: O(n)
- Extra space is used to store the rows.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {

            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += goingDown ? 1 : -1;
        }

        string ans;

        for (string row : rows)
            ans += row;

        return ans;
    }
};