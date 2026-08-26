/*
Problem: Domino
Platform: Codeforces
Problem Number: 353A
Topic: Math, Implementation

Approach:
1. Calculate the sum of all upper halves.
2. Calculate the sum of all lower halves.
3. If both sums are even:
      Answer = 0.
4. If exactly one sum is odd:
      Answer = -1
5. If both sums are odd:
      Find whether there is at least one domino containing
      one odd number and one even number.
6. If such a domino exists:
      One rotation is enough.
   Otherwise:
      It is impossible.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int upper = 0;
    int lower = 0;

    bool possible = false;

    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;

        upper += a;
        lower += b;

        // One odd and one even
        if ((a % 2) != (b % 2)) {
            possible = true;
        }
    }

    // Both sums are already even
    if (upper % 2 == 0 && lower % 2 == 0) {

        cout << 0;
    }

    // One sum is odd and the other is even
    else if ((upper % 2) != (lower % 2)) {

        cout << -1;
    }

    // Both sums are odd
    else {

        if (possible)
            cout << 1;
        else
            cout << -1;
    }

    return 0;
}
