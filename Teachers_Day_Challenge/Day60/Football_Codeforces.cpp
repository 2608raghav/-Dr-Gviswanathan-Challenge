/*
Problem: Football
Platform: Codeforces
Problem Number: 96A
Topic: String

Approach:
1. Read the string representing the players.
2. Initialize a counter to keep track of consecutive identical characters.
3. Traverse the string from the second character.
4. If the current character is the same as the previous one:
   - Increment the counter.
   - If the counter reaches 7, print "YES" and terminate.
5. Otherwise, reset the counter to 1.
6. If no sequence of 7 consecutive identical characters is found,
   print "NO".

Time Complexity: O(n)
- The string is traversed once.

Space Complexity: O(1)
- Only a counter is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int count = 1;

    for (int i = 1; i < s.size(); i++) {

        if (s[i] == s[i - 1]) {

            count++;

            if (count >= 7) {
                cout << "YES";
                return 0;
            }
        }
        else {

            count = 1;
        }
    }

    cout << "NO";

    return 0;
}