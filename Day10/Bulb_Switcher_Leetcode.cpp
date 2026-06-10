/*
Problem: Bulb Switcher
Platform: Leetcode
Topic: Math

Approach:
1. Initially all bulbs are off.
2. For each round i, every i-th bulb is toggled.
3. A bulb ends up ON only if it is toggled an odd number of times.
4. The number of toggles for a bulb equals the number of its divisors.
5. Most numbers have divisors in pairs, resulting in an even number of divisors.
6. Perfect squares have one divisor repeated (e.g., 4 → 1,2,4),
   giving them an odd number of divisors.
7. Therefore, only bulbs at perfect square positions remain ON.
8. Count the number of perfect squares less than or equal to n.
9. This count is simply floor(sqrt(n)).

Time Complexity: O(1)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};