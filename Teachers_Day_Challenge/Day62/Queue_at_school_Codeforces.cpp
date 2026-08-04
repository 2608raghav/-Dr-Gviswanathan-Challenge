/*
Problem: Queue at the School
Platform: Codeforces
Problem Number: 266B
Topic: String, Simulation

Approach:
1. Read the number of children (n), the number of seconds (t),
   and the initial queue.
2. Repeat the simulation for t seconds.
3. In each second:
   - Traverse the queue from left to right.
   - If a boy ('B') is immediately followed by a girl ('G'),
     swap them.
   - After swapping, increment the index by one extra position
     so that the moved girl is not swapped again in the same second.
4. After completing all t seconds, print the final queue.

Time Complexity: O(n × t)
- The queue is traversed once for each second.

Space Complexity: O(1)
- The string is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    while (t--) {

        for (int i = 0; i < n - 1; i++) {

            if (s[i] == 'B' && s[i + 1] == 'G') {

                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }

    cout << s;

    return 0;
}