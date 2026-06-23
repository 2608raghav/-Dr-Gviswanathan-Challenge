/*
Problem: Search Insert Position
Platform: Leetcode
Problem Number: 35
Topic: Array, Binary Search

Approach:
1. Since the array is sorted, use Binary Search.
2. Maintain two pointers:
      left = 0
      right = n - 1
3. While left <= right:
   - Compute the middle index.
   - If nums[mid] equals target:
       return mid.
   - If nums[mid] is less than target:
       search in the right half.
   - Otherwise:
       search in the left half.
4. If the target is not found:
   - left will point to the correct insertion position.
5. Return left.

Time Complexity: O(log n)
- Binary search halves the search space in each iteration.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};