/*
Problem: cAPS lOCK
Platform: Codeforces
Problem Number: 131A
Topic: String

Approach:
1. Read the input string.
2. Check whether:
   - Every character except possibly the first is uppercase.
3. If the condition is satisfied:
   - Toggle the case of every character.
4. Otherwise, leave the string unchanged.
5. Print the resulting string.

Time Complexity: O(n)
- The string is traversed a constant number of times.

Space Complexity: O(1)
- The string is modified in place.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    bool check = true;

    // Check whether all characters except the first are uppercase
    for (int i = 1; i < s.size(); i++) {

        if (islower(s[i])) {
            check = false;
            break;
        }
    }

    if (check) {

        for (char &c : s) {

            if (isupper(c))
                c = tolower(c);
            else
                c = toupper(c);
        }
    }

    cout << s;

    return 0;
}