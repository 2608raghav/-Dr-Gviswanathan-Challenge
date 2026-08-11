/*
Problem: DBMB and the Array
Platform: Codeforces
Problem Number: 2193A
Topic: Math, Array

Approach:
1. Calculate the initial sum of all elements.
2. Every operation increases the sum by exactly x.
3. Therefore, the target sum s is possible only if:
   - initial sum <= s
   - (s - initial sum) is divisible by x
4. If both conditions are satisfied, print "YES".
5. Otherwise, print "NO".

Time Complexity: O(n) per test case
- We traverse the array once to calculate its sum.

Space Complexity: O(1)
- Only the sum and input variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, s, x;
        cin >> n >> s >> x;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
        }

        if (sum <= s && (s - sum) % x == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}