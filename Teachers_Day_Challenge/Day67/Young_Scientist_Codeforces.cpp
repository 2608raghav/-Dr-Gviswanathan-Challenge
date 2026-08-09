/*
Problem: Young Physicist
Platform: Codeforces
Problem Number: 69A
Topic: Math, Implementation

Approach:
1. Read the number of force vectors.
2. Maintain three variables to store the sum of:
   - X-components
   - Y-components
   - Z-components
3. For every vector, add its x, y, and z components to the
   corresponding sums.
4. If all three sums are zero, the resultant force is zero and
   the body is in equilibrium.
5. Otherwise, the body is not in equilibrium.

Time Complexity: O(n)
- Each vector is processed exactly once.

Space Complexity: O(1)
- Only three variables are used to store the sums.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n; i++) {

        int a, b, c;
        cin >> a >> b >> c;

        x += a;
        y += b;
        z += c;
    }

    if (x == 0 && y == 0 && z == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}