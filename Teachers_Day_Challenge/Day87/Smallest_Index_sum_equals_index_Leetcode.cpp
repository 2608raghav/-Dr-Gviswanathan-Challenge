/*
Problem: Smallest Index With Digit Sum Equal to Index
Platform: LeetCode
Problem Number: 3550
Topic: Array, Math, Digit Sum

Approach:
1. Traverse the array from left to right using index i.

2. For each element nums[i], calculate the sum of its digits:
   - Extract the last digit using num % 10.
   - Add the digit to digitSum.
   - Remove the last digit using num /= 10.
   - Repeat until num becomes 0.

3. Compare the digitSum with the current index i.

4. If digitSum == i, return i immediately.
   - Since we traverse from left to right, the first
     matching index is the smallest index.

5. If no index satisfies the condition, return -1.

Example:
   nums = [1, 10, 11]

   Index 0:
      nums[0] = 1
      Digit sum = 1
      1 != 0

   Index 1:
      nums[1] = 10
      Digit sum = 1 + 0 = 1
      1 == 1
      Return 1

Time Complexity: O(n * d)
- n = number of elements in nums.
- d = maximum number of digits in an element.
- We visit each element and calculate its digit sum.
- Since nums[i] <= 1000, each element has at most 4 digits.
  Therefore, this is effectively O(n).

Space Complexity: O(1)
- Only a few integer variables are used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        // Traverse the array from left to right
        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            int digitSum = 0;

            // Calculate the sum of digits
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }

            // Check whether digit sum equals the index
            if (digitSum == i) {
                return i;
            }
        }

        // No valid index found
        return -1;
    }
};