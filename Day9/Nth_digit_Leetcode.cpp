/*
Problem: Nth Digit
Platform: Leetcode
Topic: Math

Approach:
1. Digits are grouped according to the number of digits in the numbers:
   - 1-digit numbers: 1 to 9      → 9 × 1 digits
   - 2-digit numbers: 10 to 99    → 90 × 2 digits
   - 3-digit numbers: 100 to 999  → 900 × 3 digits
   and so on.
2. Repeatedly subtract the total number of digits in each group from n until we find the group that contains the nth digit.
3. Once the correct group is found:
   - Determine the actual number containing the nth digit.
   - Find the exact digit position within that number.
4. Convert the number to a string and return the required digit.

Time Complexity: O(log n)
- The number of digit groups is very small (at most 9 for a 32-bit integer).

Space Complexity: O(1)
- Only a constant amount of extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;

        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        long long number = start + (n - 1) / digits;
        string numStr = to_string(number);

        return numStr[(n - 1) % digits] - '0';
    }
};