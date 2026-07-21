/*
Problem: Single Number
Platform: Leetcode
Problem Number: 136
Topic: Bit Manipulation

Approach:
1. Initialize the answer as 0.
2. Traverse every element in the array.
3. Perform XOR between the current answer and the current element.
4. Since:
   - x ^ x = 0
   - x ^ 0 = x
   all duplicate elements cancel each other out.
5. The remaining value is the element that appears only once.
6. Return the answer.

Time Complexity: O(n)
- The array is traversed once.

Space Complexity: O(1)
- Only one variable is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};