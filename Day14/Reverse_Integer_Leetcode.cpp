/*
Problem: Reverse Integer
Platform: Leetcode
Problem Number: 7
Topic: Math

Approach:
1. Extract the last digit of the number using:
      digit = x % 10
2. Remove the last digit from the number:
      x /= 10
3. Build the reversed number:
      reverse = reverse * 10 + digit
4. Before updating the reversed number, check for overflow:
   - If reverse exceeds the 32-bit signed integer range,
     return 0.
5. Continue until all digits have been processed.
6. Return the reversed integer.

Time Complexity: O(log10(n))
- One iteration per digit.

Space Complexity: O(1)
- Constant extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while(x != 0) {
            int digit = x % 10;
            x /= 10;

            if(ans > INT_MAX / 10 ||
               (ans == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if(ans < INT_MIN / 10 ||
               (ans == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            ans = ans * 10 + digit;
        }

        return ans;
    }
};