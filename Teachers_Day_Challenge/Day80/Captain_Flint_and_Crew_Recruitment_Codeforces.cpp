/*
Problem: Captain Flint and Crew Recruitment
Platform: Codeforces
Problem Number: 1388A
Topic: Constructive Algorithm, Math, Number Theory

Approach:
1. We need four different positive integers.
2. At least three of them must be nearly prime.

3. Use three fixed nearly prime numbers:
      6, 10, 14

   Their sum is:
      6 + 10 + 14 = 30

4. If n <= 30:
      It is impossible to construct four different
      positive integers satisfying the conditions.

5. For most values of n > 30:
      6 10 14 (n - 30)

6. Special cases:
      n = 36, 40, 44

   In these cases, n - 30 becomes 6, 10, or 14,
   causing duplicate numbers.

   Therefore, use:
      6 10 15 (n - 31)

Time Complexity: O(t)
- Each test case takes constant time.

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        if (n <= 30) {

            cout << "NO\n";
        }
        else {

            cout << "YES\n";

            // Special cases to avoid duplicate numbers
            if (n == 36 || n == 40 || n == 44) {

                cout << 6 << " "
                     << 10 << " "
                     << 15 << " "
                     << n - 31 << "\n";
            }
            else {

                cout << 6 << " "
                     << 10 << " "
                     << 14 << " "
                     << n - 30 << "\n";
            }
        }
    }

    return 0;
}