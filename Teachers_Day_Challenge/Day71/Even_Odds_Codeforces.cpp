/*
Problem: Even Odds
Platform: Codeforces
Problem Number: 318A
Topic: Math

Approach:
1. The sequence contains all odd numbers first, followed by all even numbers.
   For example, for n = 10:

   1 3 5 7 9 2 4 6 8 10

2. Calculate how many odd numbers are present:
      oddCount = (n + 1) / 2

3. If k is within the odd-number section:
      answer = 2 * k - 1

4. Otherwise, k belongs to the even-number section.
   Its position within the even section is:
      k - oddCount

   Therefore:
      answer = 2 * (k - oddCount)

Time Complexity: O(1)
- Only arithmetic operations are performed.

Space Complexity: O(1)
- No extra space is used.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;

    long long oddCount = (n + 1) / 2;

    if (k <= oddCount) {

        cout << 2 * k - 1;
    }
    else {

        cout << 2 * (k - oddCount);
    }

    return 0;
}