/*
Problem: Count Primes
Platform: Leetcode
Problem Number: 204
Topic: Math, Sieve of Eratosthenes

Approach:
1. If n is less than or equal to 2, return 0 since there are no
   prime numbers less than 2.
2. Create a boolean array of size n and mark every number as prime.
3. Mark 0 and 1 as non-prime.
4. Traverse from 2 to √n:
   - If the current number is prime,
     mark all of its multiples as non-prime.
5. Count all remaining prime numbers from 2 to n - 1.
6. Return the count.

Time Complexity: O(n log log n)
- Using the Sieve of Eratosthenes.

Space Complexity: O(n)
- A boolean array of size n is used.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {

            if (isPrime[i]) {

                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i])
                count++;
        }

        return count;
    }
};