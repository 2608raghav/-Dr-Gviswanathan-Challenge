/*
Problem: Park Lighting
Platform: Codeforces
Problem Number: 1358A
Topic: Math

Approach:
1. Each lamp illuminates at most two adjacent cells.
2. Therefore, the number of lamps required is:
      ceil(n * m / 2)
3. We can calculate this using integer arithmetic:
      (n * m + 1) / 2
4. Repeat this calculation for every test case.

Time Complexity: O(t)
- Each test case requires only constant-time arithmetic.

Space Complexity: O(1)
- No extra space is required.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        long long n, m;
        cin >> n >> m;

        cout << (n * m + 1) / 2 << endl;
    }

    return 0;
}