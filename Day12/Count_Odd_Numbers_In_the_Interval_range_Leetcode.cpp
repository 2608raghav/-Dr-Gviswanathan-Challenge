/*
Problem: Count Odd Numbers in an Interval Range
Platform: Leetcode
Problem Number: 1523
Topic: Math

Approach:
1. Calculate the total numbers present in the interval:
      count = high - low + 1
2. If count is even:
   - Exactly half of the numbers are odd.
   - Return count / 2.
3. If count is odd:
   - The count of odd numbers depends on the parity of low.
   - If low is odd, there is one extra odd number.
   - Otherwise, there is one extra even number.
4. Return the computed count of odd numbers.

Alternative Formula:
   (high + 1) / 2 - low / 2

Time Complexity: O(1)

Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};