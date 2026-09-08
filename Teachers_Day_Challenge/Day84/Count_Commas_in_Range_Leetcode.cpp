
/*
Problem: Count Commas in Range
Platform: LeetCode
Problem Number: 3870
Topic: Math

Approach:
1. Numbers from 1 to 999 contain no commas.

2. The first number containing a comma is:
      1,000

3. Since n <= 100,000, every number from
   1,000 to n contains exactly one comma.

4. Therefore, count how many numbers are in the range:
      [1000, n]

   Number of elements:
      n - 1000 + 1
      = n - 999

5. If n < 1000, no number contains a comma.

Therefore:

      answer = max(0, n - 999)

Time Complexity: O(1)
- The answer is calculated directly.

Space Complexity: O(1)
- No extra data structure is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {

        return max(0, n - 999);
    }
};

