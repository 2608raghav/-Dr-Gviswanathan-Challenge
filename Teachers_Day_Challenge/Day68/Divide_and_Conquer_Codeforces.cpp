/*
Problem: Divide and Conquer
Platform: Codeforces
Problem Number: 2241A
Topic: Greedy, Math, Number Theory

Approach:
1. We can choose any positive divisor z of x and replace x by x / z.
2. Therefore, x can only be reduced by dividing it.
3. To make x exactly equal to y, y must divide x.
4. If x % y == 0, we can simply choose:
      z = x / y
   and obtain x = y.
5. Otherwise, it is impossible.

Time Complexity: O(1)
- Only one divisibility check is required.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int x, y;
        cin >> x >> y;

        if (x % y == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}