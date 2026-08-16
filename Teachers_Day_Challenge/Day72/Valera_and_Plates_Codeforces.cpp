/*
Problem: Valera and Plates
Platform: Codeforces
Problem Number: 369A
Topic: Greedy

Approach:
1. Read n, m and k:
   - n = number of days
   - m = number of clean bowls
   - k = number of clean plates

2. For each day:
   - Type 1:
       Must use a bowl.
       If a bowl is available, use it.
       Otherwise, wash a bowl.

   - Type 2:
       Can use either a bowl or a plate.
       We should use a plate first because bowls are required
       for type 1 dishes.
       If no plate is available, use a bowl.
       If neither is available, wash one utensil.

3. Count the number of times washing is required.

Time Complexity: O(n)
- Each day is processed exactly once.

Space Complexity: O(1)
- Only the bowl, plate and washing counters are maintained.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    int wash = 0;

    while (n--) {

        int x;
        cin >> x;

        if (x == 1) {

            // Type 1 must be eaten from a bowl
            if (m > 0)
                m--;
            else
                wash++;
        }

        else {

            // Type 2 can use either plate or bowl
            if (k > 0)
                k--;
            else if (m > 0)
                m--;
            else
                wash++;
        }
    }

    cout << wash;

    return 0;
}