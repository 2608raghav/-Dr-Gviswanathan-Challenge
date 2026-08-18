/*
Problem: Jzzhu and Children
Platform: Codeforces
Problem Number: 450A
Topic: Queue, Simulation

Approach:
1. Store all children in a queue along with their indices.
2. Give m candies to the child at the front.
3. If the child still needs candies:
   - Put the child back at the end of the queue.
4. Otherwise:
   - Remove the child permanently.
   - Update the answer with that child's index.
5. Continue until the queue becomes empty.
6. The last child removed is the answer.

Time Complexity: O(total number of turns)
- Each child may return to the queue multiple times.

Space Complexity: O(n)
- The queue stores at most n children.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {

        int candies;
        cin >> candies;

        q.push({candies, i});
    }

    int ans = 0;

    while (!q.empty()) {

        auto [need, index] = q.front();
        q.pop();

        need -= m;

        if (need > 0) {
            q.push({need, index});
        }
        else {
            ans = index;
        }
    }

    cout << ans;

    return 0;
}