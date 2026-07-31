/*
Problem: George and Accommodation
Platform: Codeforces
Problem Number: 467A
Topic: Implementation

Approach:
1. Read the number of rooms.
2. Initialize a counter for the number of rooms George can move into.
3. For each room:
   - Read the current number of occupants (p).
   - Read the room capacity (q).
4. If the room has space for at least two more people:
      q - p >= 2
   increment the counter.
5. After checking all rooms, print the counter.

Time Complexity: O(n)
- n is the number of rooms.

Space Complexity: O(1)
- Only a few integer variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int count = 0;

    while (n--) {

        int p, q;
        cin >> p >> q;

        if (q - p >= 2)
            count++;
    }

    cout << count;

    return 0;
}