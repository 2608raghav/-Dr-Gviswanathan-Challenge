/*
Problem: Three Pairwise Maximums
Platform: Codeforces
Problem Number: 1385A
Topic: Sorting, Greedy

Approach:
1. Read the three pairwise maximum values.
2. Sort them.
3. Let:
      x <= y <= z
4. For a valid answer, the two largest values must be equal:
      y == z
5. If y != z:
      No valid a, b, c exist.
6. Otherwise, a valid triple is:
      x y y

Why?
The largest of the three pairwise maximums must appear at
least twice because the largest element among a, b, c is
involved in two pairs.

Time Complexity: O(1)
- Only three numbers are sorted.

Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b, c;
        cin >> a >> b >> c;

        vector<int> v = {a, b, c};

        sort(v.begin(), v.end());

        if (v[1] != v[2]) {

            cout << "NO\n";
        }
        else {

            cout << "YES\n";

            cout << v[0] << " "
                 << v[1] << " "
                 << v[2] << "\n";
        }
    }

    return 0;
}