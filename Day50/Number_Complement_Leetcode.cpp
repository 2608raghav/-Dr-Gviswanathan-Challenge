/*
Problem: Number Complement
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. Create a bitmask having all bits set to 1 up to the most
   significant bit of the given number.
2. Keep left-shifting the mask until it becomes greater than
   or equal to the number.
3. Subtract 1 from the mask to obtain a sequence of all 1s.
4. XOR the number with the mask.
5. The XOR operation flips every bit within the valid range,
   producing the complement.
6. Return the complemented number.

Time Complexity: O(log n)
- Depends on the number of bits in the integer.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {

        int mask = 1;

        while (mask <= num) {
            mask <<= 1;
        }

        mask -= 1;

        return num ^ mask;
    }
};