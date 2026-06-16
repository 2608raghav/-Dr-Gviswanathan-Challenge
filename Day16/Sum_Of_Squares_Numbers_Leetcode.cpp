/*
Problem: Sum of Square Numbers
Platform: Leetcode
Problem Number: 633
Topic: Math, Two Pointers

Approach:
1. Initialize two pointers:
   - left = 0
   - right = floor(sqrt(c))
2. While left <= right:
   - Compute:
         sum = left² + right²
   - If sum == c:
         return true
   - If sum < c:
         increase left to make the sum larger
   - If sum > c:
         decrease right to make the sum smaller
3. If no valid pair is found, return false.
4. Using two pointers avoids checking every possible pair.

Time Complexity: O(√c)
- In each iteration, either left increases or right decreases.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while (left <= right) {
            long long sum = left * left + right * right;

            if (sum == c) {
                return true;
            }
            else if (sum < c) {
                left++;
            }
            else {
                right--;
            }
        }

        return false;
    }
};