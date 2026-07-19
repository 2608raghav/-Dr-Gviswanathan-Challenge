/*
Problem: Number of 1 Bits
Platform: Leetcode
Problem Number: 191
Topic: Bit Manipulation

Approach:
1. Initialize a counter to 0.
2. Traverse the binary representation of the number.
3. In each iteration:
   - Check whether the least significant bit is 1.
   - If yes, increment the counter.
   - Right shift the number by one bit.
4. Repeat until the number becomes 0.
5. Return the total number of set bits.

Time Complexity: O(32)
- A 32-bit integer has at most 32 bits to examine.
- This is effectively O(1).

Space Complexity: O(1)
- Only a counter is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;

        while (n > 0) {

            if (n & 1)
                count++;

            n >>= 1;
        }

        return count;
    }
};