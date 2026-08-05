/*
Problem: Xenia and Ringroad
Platform: Codeforces
Problem Number: 339B
Topic: Implementation

Approach:
1. Read the number of houses (n) and the number of tasks (m).
2. Initialize:
   - current = 1 (Xenia starts at house 1).
   - time = 0.
3. Traverse each task:
   - Read the destination house.
   - If the destination is ahead of or equal to the current house,
     move directly:
        time += destination - current.
   - Otherwise, complete one full round of the ringroad:
        time += (n - current) + destination.
   - Update the current house.
4. After completing all tasks, print the total time.

Time Complexity: O(m)
- Each task is processed exactly once.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m;
    cin >> n >> m;

    long long current = 1;
    long long time = 0;

    while (m--) {

        long long destination;
        cin >> destination;

        if (destination >= current)
            time += destination - current;
        else
            time += (n - current) + destination;

        current = destination;
    }

    cout << time;

    return 0;
}