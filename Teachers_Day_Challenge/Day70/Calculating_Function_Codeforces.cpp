/*
Problem: Calculating Function
Platform: Codeforces
Problem Number: 486A
Topic: Math

Approach:
1. The function is defined as:
      f(n) = -1 + 2 - 3 + 4 - 5 + ... + (-1)^n * n
2. Instead of calculating every term, observe the pattern:
   - If n is even:
        f(n) = n / 2
   - If n is odd:
        f(n) = -(n + 1) / 2
3. Use this mathematical observation to calculate the answer
   directly.

Time Complexity: O(1)
- Only a few arithmetic operations are performed.

Space Complexity: O(1)
- No extra space is required.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;

    if (n % 2 == 0)
        cout << n / 2;
    else
        cout << -(n + 1) / 2;

    return 0;
}