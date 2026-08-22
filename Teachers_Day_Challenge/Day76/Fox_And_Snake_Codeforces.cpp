/*
Problem: Fox And Snake
Platform: Codeforces
Problem Number: 510A
Topic: Implementation

Approach:
1. The snake is represented using '#'.
2. For odd-numbered rows:
   - Print '#' across the entire row.
3. For even-numbered rows:
   - Alternately print the '#' at the right side and left side.
4. This creates the required snake pattern.

For example, n = 5, m = 5:

#####
    #
#####
#    
#####

Time Complexity: O(n * m)
- We print every cell of the n x m grid.

Space Complexity: O(1)
- No extra data structure is required.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {

        if (i % 2 == 1) {

            // Odd rows: completely filled
            for (int j = 0; j < m; j++) {
                cout << '#';
            }
        }

        else {

            // Even rows: place # on alternating sides
            if ((i / 2) % 2 == 1) {

                cout << string(m - 1, '.');
                cout << '#';
            }

            else {

                cout << '#';
                cout << string(m - 1, '.');
            }
        }

        cout << '\n';
    }

    return 0;
}