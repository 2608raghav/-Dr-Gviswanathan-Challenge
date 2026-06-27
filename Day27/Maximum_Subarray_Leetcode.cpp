/*
Problem: Maximum Subarray
Platform: Leetcode
Problem Number: 53
Topic: Array, Dynamic Programming, Kadane's Algorithm

Approach:
1. Initialize:
   - currentSum = 0
   - maximumSum = INT_MIN
2. Traverse the array.
3. At each element:
   - Add the current element to currentSum.
   - Update maximumSum with the larger of maximumSum and currentSum.
4. If currentSum becomes negative:
   - Reset currentSum to 0 since a negative sum cannot contribute
     to a maximum subarray in the future.
5. After processing all elements, return maximumSum.

Time Complexity: O(n)
- The array is traversed exactly once.

Space Complexity: O(1)
- Only two variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int maximumSum = INT_MIN;

        for(int num : nums) {

            currentSum += num;

            maximumSum = max(maximumSum, currentSum);

            if(currentSum < 0) {
                currentSum = 0;
            }
        }

        return maximumSum;
    }
};