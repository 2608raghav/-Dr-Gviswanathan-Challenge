/*
Problem: Find the Duplicate Number
Platform: Leetcode
Problem Number: 287
Topic: Array, Two Pointers, Floyd's Cycle Detection

Approach:
1. Treat the array as a linked list where:
      next = nums[current]
2. Since one number is duplicated, a cycle is formed.
3. Use Floyd's Cycle Detection Algorithm:
   - Initialize slow and fast pointers at nums[0].
   - Move:
       slow = nums[slow]
       fast = nums[nums[fast]]
   - Continue until they meet inside the cycle.
4. Reset one pointer to nums[0].
5. Move both pointers one step at a time.
6. The point where they meet again is the duplicate number.
7. Return the duplicate number.

Time Complexity: O(n)
- Both phases of Floyd's algorithm traverse the array at most once.

Space Complexity: O(1)
- Only two pointers are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find the meeting point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};