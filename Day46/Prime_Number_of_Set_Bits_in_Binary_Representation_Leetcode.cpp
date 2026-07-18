/*
Problem: Prime Number of Set Bits in Binary Representation
Platform: Leetcode
Problem Number: 762
Topic: Bit Manipulation, Math

Approach:
1. Traverse every number from left to right.
2. For each number:
   - Count the number of set bits using a helper function.
   - The helper function repeatedly divides the number by 2
     and counts the set bits.
3. Check whether the number of set bits is prime using
   another helper function.
4. If the count of set bits is prime, increment the answer.
5. Return the total count.

Time Complexity: O((right - left + 1) × log N)
- Counting set bits takes O(log N).
- Checking primality takes O(√log N), which is effectively constant
  since the maximum number of set bits is small.

Space Complexity: O(1)
- Only a constant amount of extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool prime(int n) {

        if (n <= 1) {
            return false;
        }

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

   int setbits(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2)
            count++;
        n /= 2;
    }
    return count;
}

    int countPrimeSetBits(int left, int right) {

        int res = 0;

        while (left <= right) {

            int temp = setbits(left);

            if (prime(temp)) {
                res++;
            }

            left++;
        }

        return res;
    }
};