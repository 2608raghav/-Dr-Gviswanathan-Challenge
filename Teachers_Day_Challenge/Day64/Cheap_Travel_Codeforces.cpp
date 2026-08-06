/*
Problem: Cheap Travel
Platform: Codeforces
Problem Number: 466A
Topic: Math, Greedy

Approach:
1. Read:
   - n: Number of rides required.
   - m: Number of rides covered by a special ticket.
   - a: Cost of a single ride ticket.
   - b: Cost of a special ticket.
2. Compute the minimum cost using three possible strategies:
   - Buy all rides using single tickets.
   - Buy only special tickets (including one extra if needed).
   - Buy as many special tickets as possible and purchase the
     remaining rides individually.
3. Return the minimum among these three costs.

Time Complexity: O(1)
- Only a few arithmetic operations are performed.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int cost1 = n * a;

    int cost2 = ((n + m - 1) / m) * b;

    int cost3 = (n / m) * b + min((n % m) * a, b);

    cout << min({cost1, cost2, cost3});

    return 0;
}