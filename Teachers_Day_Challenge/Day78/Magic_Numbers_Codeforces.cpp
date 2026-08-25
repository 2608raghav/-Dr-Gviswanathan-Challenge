/*
Problem: Magic Number
Platform: Codeforces
Problem Number: 320A
Topic: String, Greedy

Approach:
1. Start from the beginning of the string.
2. At every position:
   - If "144" starts here, consume 3 characters.
   - Else if "14" starts here, consume 2 characters.
   - Else if '1' is present, consume 1 character.
   - Otherwise, the string is invalid.
3. If we reach the end, the string is a magic number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int i = 0;

    while (i < s.size()) {

        if (s.substr(i, 3) == "144") {
            i += 3;
        }
        else if (s.substr(i, 2) == "14") {
            i += 2;
        }
        else if (s[i] == '1') {
            i++;
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}