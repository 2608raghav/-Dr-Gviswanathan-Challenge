/*
Problem: Kefa and First Steps
Platform: Codeforces
Problem Number: 580A
Topic: Array, Dynamic Programming

Approach:
1. Read the number of days n and the sequence of income values.
2. Maintain two variables:
   - current = length of the current non-decreasing segment.
   - ans = maximum length found so far.
3. Start with current = 1.
4. For every adjacent pair:
   - If a[i] >= a[i-1], the non-decreasing sequence continues,
     so increment current.
   - Otherwise, reset current to 1.
5. Update ans after every comparison.
6. Print the maximum length.

Time Complexity: O(n)
- The array is traversed once.

Space Complexity: O(n)
- The array is stored.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int current = 1;
    int ans = 1;

    for (int i = 1; i < n; i++) {

        if (a[i] >= a[i - 1]) {
            current++;
        }
        else {
            current = 1;
        }

        ans = max(ans, current);
    }

    cout << ans;

    return 0;
}