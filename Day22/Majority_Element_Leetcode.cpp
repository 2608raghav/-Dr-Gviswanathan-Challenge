/*
Problem: Majority Element
Platform: Leetcode
Problem Number: 169
Topic: Array, Boyer-Moore Voting Algorithm

Approach:
1. Maintain:
   - candidate: potential majority element.
   - count: current vote balance.
2. Traverse the array.
3. For each element:
   - If count becomes 0:
       - Select the current element as the new candidate.
   - If the current element equals the candidate:
       - Increment count.
   - Otherwise:
       - Decrement count.
4. Since the majority element appears more than n/2 times,
   all other elements together cannot completely cancel it out.
5. After the traversal, the candidate is guaranteed to be the
   majority element.
6. Return the candidate.

Time Complexity: O(n)
- Single traversal of the array.

Space Complexity: O(1)
- Only two variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        return candidate;
    }
};