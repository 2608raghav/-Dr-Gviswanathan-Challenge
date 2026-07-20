/*
Problem: Hamming Distance
Platform: Leetcode
Problem Number: 461
Topic: Bit Manipulation

Approach:
1. Compute the XOR of the two numbers:
      xorValue = x ^ y
2. In the XOR result:
   - Every set bit (1) represents a position where
     x and y have different bits.
3. Count the number of set bits in xorValue.
4. Return the count as the Hamming Distance.

Time Complexity: O(32)
- A 32-bit integer has at most 32 bits to examine.
- This is effectively O(1).

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

        int xorValue = x ^ y;
        int count = 0;

        while (xorValue > 0) {

            if (xorValue & 1)
                count++;

            xorValue >>= 1;
        }

        return count;
    }
};