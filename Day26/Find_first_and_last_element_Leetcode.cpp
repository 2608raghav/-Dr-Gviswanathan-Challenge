/*
Problem: Find First and Last Position of Element in Sorted Array
Platform: Leetcode
Problem Number: 34
Topic: Array, Binary Search

Approach:
1. Since the array is sorted, use Binary Search twice.
2. First Binary Search:
   - Find the first (leftmost) occurrence of the target.
   - Whenever the target is found, store its index and continue
     searching in the left half.
3. Second Binary Search:
   - Find the last (rightmost) occurrence of the target.
   - Whenever the target is found, store its index and continue
     searching in the right half.
4. If the target is not found, return {-1, -1}.
5. Otherwise, return the indices of the first and last occurrences.

Time Complexity: O(log n)
- Two binary searches are performed.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1, last = -1;
        int left = 0, right = nums.size() - 1;

        // Find first occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;

        // Find last occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return {first, last};
    }
};