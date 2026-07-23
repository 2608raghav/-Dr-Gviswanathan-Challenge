/*
Problem: Find Numbers with Even Number of Digits
Platform: Leetcode
Topic: Array, Math

Approach:
1. Initialize a counter to store the number of integers having
   an even number of digits.
2. Traverse each number in the array.
3. For every number:
   - Count its digits by repeatedly dividing it by 10.
4. If the digit count is even, increment the answer.
5. Return the final count.

Time Complexity: O(n × log M)
- n = size of the array.
- M = maximum value in the array.
- Counting digits for each number takes O(log M).

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {

        int digits = 0;

        while (num > 0) {
            digits++;
            num /= 10;
        }

        return digits;
    }

    int findNumbers(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {

            if (countDigits(num) % 2 == 0)
                ans++;
        }

        return ans;
    }
};