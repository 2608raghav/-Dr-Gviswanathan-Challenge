/*
Problem: Tavas and SaDDas
Platform: Codeforces
Problem Number: 535B
Topic: Math, Bit Manipulation

Approach:
1. The number consists only of digits 4 and 7.
2. Think of every valid number as a binary representation:
      4 -> 0
      7 -> 1

3. For a number of length `size`, all shorter lucky numbers
   come before it.

4. The number of lucky numbers having length less than `size` is:
      2^1 + 2^2 + ... + 2^(size-1)
      = 2^size - 2

5. For the given number, traverse its digits from right to left.
   - If the digit is 7, add 2^position.
   - If the digit is 4, add nothing.

6. Finally add 1 because the rank is 1-indexed.

For example:
      47

Map:
      4 -> 0
      7 -> 1

Binary representation:
      01

Numbers before length 2:
      4

Rank:
      1 + 1 + 1 = 3

Therefore:
      47 -> 3

Time Complexity: O(n)
- We traverse the digits once.

Space Complexity: O(1)
- Only a few variables are used.
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    char s[20];
    cin >> s;

    int size = strlen(s);

    ll ans = 0;

    ans = (1 << size) - 2;

    
    for (ll i = size - 1, count = 0;
         i >= 0;
         i--, count++) {

        if (s[i] == '7') {
            ans += (1 << count);
        }
    }

    
    cout << (ans + 1);

    return 0;
}