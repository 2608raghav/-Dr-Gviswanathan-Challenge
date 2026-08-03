/*
Problem: Dubstep
Platform: Codeforces
Problem Number: 208A
Topic: String

Approach:
1. Read the remixed song as a string.
2. Traverse the string using an index.
3. Whenever the substring "WUB" is found:
   - Skip all consecutive occurrences of "WUB".
   - If at least one word has already been printed,
     print a single space.
4. Otherwise:
   - Print the current character.
   - Continue until the next "WUB" is encountered.
5. This reconstructs the original song with words separated
   by a single space.

Time Complexity: O(n)
- The string is traversed once.

Space Complexity: O(1)
- No extra space is used apart from a few variables.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    bool firstWord = true;

    for (int i = 0; i < s.size();) {

        if (i + 2 < s.size() && s.substr(i, 3) == "WUB") {

            while (i + 2 < s.size() && s.substr(i, 3) == "WUB")
                i += 3;

            if (i < s.size() && !firstWord)
                cout << " ";
        }
        else {

            cout << s[i];
            firstWord = false;
            i++;
        }
    }

    return 0;
}