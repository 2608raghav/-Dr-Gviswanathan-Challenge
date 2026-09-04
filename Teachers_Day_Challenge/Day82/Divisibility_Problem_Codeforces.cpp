/*
Problem: Divisibility Problem
Platform: Codeforces
Problem Number: 1328A
Topic: Math, Implementation

Approach:
1. Find the remainder when a is divided by b.
2. If the remainder is 0:
      a is already divisible by b.
      Answer = 0.
3. Otherwise:
      Find how much needs to be added to reach
      the next multiple of b.

      Answer = b - (a % b)

Time Complexity: O(t)
- Each test case takes O(1).

Space Complexity: O(1)
- Only a few variables are used.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int remainder = a % b;

        int answer;

        if (remainder == 0) {
            answer = 0;
        }
        else {
            answer = b - remainder;
        }

        cout << answer << "\n";
    }

    return 0;
}