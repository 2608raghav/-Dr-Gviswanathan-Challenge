/*
Problem: Check If It Is a Good Array
Platform: Leetcode
Problem Number: 1250
Topic: Math, Number Theory

Approach:
1. Compute the Greatest Common Divisor (GCD) of all elements
   in the array.
2. Traverse the array:
   - Update the current GCD using gcd(currentGCD, nums[i]).
3. After processing all elements:
   - If the final GCD is 1, return true.
   - Otherwise, return false.
4. This is based on Bézout's Identity, which states that a linear
   combination of the array elements can equal 1 if and only if
   their GCD is 1.

Time Complexity: O(n × log M)
- n = size of the array.
- M = maximum element in the array.

Space Complexity: O(1)
- Only one variable is used to store the running GCD.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {

        int g = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            g = gcd(g, nums[i]);
        }

        return g == 1;
    }
};