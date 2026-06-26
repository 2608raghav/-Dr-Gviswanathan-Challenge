/*
Problem: Rotate Array
Platform: Leetcode
Topic: Array, Two Pointers

Approach:
1. Let n be the size of the array.
2. Compute:
      k = k % n
   since rotating by n positions leaves the array unchanged.
3. Reverse the entire array.
4. Reverse the first k elements.
5. Reverse the remaining n - k elements.
6. The array is now rotated to the right by k positions.

Time Complexity: O(n)
- The array is reversed three times.

Space Complexity: O(1)
- Rotation is performed in-place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};