/*
Problem: Night at the Museum
Platform: Codeforces
Problem Number: 731A
Topic: String, Greedy

Approach:
1. The pointer initially starts at the letter 'a'.
2. For every character in the string:
   - Calculate the clockwise distance from the current character
     to the target character.
   - Calculate the counter-clockwise distance.
   - Take the minimum of the two distances.
3. Add this minimum distance to the total.
4. Move the pointer to the current target character.
5. Return the total rotations.

Time Complexity: O(n)
- Each character is processed once.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    char current = 'a';
    int ans = 0;

    for (char c : s) {

        int diff = abs(c - current);

        ans += min(diff, 26 - diff);

        current = c;
    }

    cout << ans;

    return 0;
}