/*
Problem: Sort Colors
Platform: LeetCode
Problem Number: 75
Topic: Array, Two Pointers, Dutch National Flag

Approach:
1. Use three pointers:
      low  = 0
      mid  = 0
      high = n - 1

2. Maintain three regions:
      [0 ... low-1]     -> 0s
      [low ... mid-1]   -> 1s
      [mid ... high]    -> Unknown elements
      [high+1 ... n-1]  -> 2s

3. Process nums[mid]:

   Case 1: nums[mid] == 0
      Swap nums[low] and nums[mid].
      Increment low and mid.

   Case 2: nums[mid] == 1
      It is already in the correct region.
      Increment mid.

   Case 3: nums[mid] == 2
      Swap nums[mid] and nums[high].
      Decrement high.
      Do NOT increment mid because the new value at mid
      has not been checked yet.

4. Continue until mid > high.

Time Complexity: O(n)
- Every element is processed at most a constant number of times.

Space Complexity: O(1)
- Sorting is performed in-place.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {

                
                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if (nums[mid] == 1) {

                
                mid++;
            }

            else {

                swap(nums[mid], nums[high]);

                high--;

                
            }
        }
    }
};

