/*
Problem: Find Greatest Common Divisor of Array
Platform: Leetcode
Problem Number: 1979
Topic: Array, Math

Approach:
1. Traverse the array to find:
   - The minimum element.
   - The maximum element.
2. The GCD of the entire array must divide both the minimum
   and maximum elements.
3. Compute the GCD of the minimum and maximum values using
   Euclid's Algorithm.
4. Return the resulting GCD.

Time Complexity: O(n + log(minElement))
- O(n) to find the minimum and maximum elements.
- O(log(minElement)) for GCD computation.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        return gcd(mini, maxi);
    }
};