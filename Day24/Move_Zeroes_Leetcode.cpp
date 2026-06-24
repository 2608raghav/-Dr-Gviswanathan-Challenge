/*
Problem: Move Zeroes
Platform: Leetcode
Problem Number: 283
Topic: Array, Two Pointers

Approach:
1. Maintain a pointer 'index' indicating the position where the next
   non-zero element should be placed.
2. Traverse the array:
   - Whenever a non-zero element is found,
     swap it with nums[index].
   - Increment index.
3. After processing all elements:
   - All non-zero elements are moved to the front while maintaining
     their relative order.
   - All zeroes automatically shift to the end.
4. Return the modified array.

Time Complexity: O(n)
- Single traversal of the array.

Space Complexity: O(1)
- In-place modification without extra storage.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int index = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {

                swap(nums[index], nums[i]);

                index++;
            }
        }
    }
};