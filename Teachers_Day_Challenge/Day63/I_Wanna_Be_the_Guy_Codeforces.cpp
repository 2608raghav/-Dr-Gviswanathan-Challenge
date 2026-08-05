/*
Problem: I Wanna Be the Guy
Platform: Codeforces
Problem Number: 469A
Topic: Set, Implementation

Approach:
1. Read the total number of levels (n).
2. Create a set to store all levels that can be completed.
3. Read the levels Little X can pass and insert them into the set.
4. Read the levels Little Y can pass and insert them into the set.
5. After processing both players:
   - If the set contains all n levels,
     print "I become the guy."
   - Otherwise,
     print "Oh, my keyboard!".

Time Complexity: O((p + q) log n)
- p and q are the numbers of levels Little X and Little Y can pass.

Space Complexity: O(n)
- The set stores at most n distinct levels.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    set<int> levels;

    int p;
    cin >> p;

    while (p--) {
        int x;
        cin >> x;
        levels.insert(x);
    }

    int q;
    cin >> q;

    while (q--) {
        int y;
        cin >> y;
        levels.insert(y);
    }

    if (levels.size() == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";

    return 0;
}