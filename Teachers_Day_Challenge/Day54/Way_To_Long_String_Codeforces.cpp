/*
Problem: Way Too Long Words
Platform: Codeforces
Problem Number: 71A
Topic: String

Approach:
1. Read the number of test cases.
2. For each word:
   - If its length is less than or equal to 10,
     print the word as it is.
   - Otherwise:
     a. Print the first character.
     b. Print the number of characters between the first and last characters.
     c. Print the last character.
3. Repeat for all test cases.

Time Complexity: O(n)
- n is the total number of characters across all input words.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        if (s.length() <= 10) {
            cout << s << endl;
        }
        else {
            cout << s.front()
                 << s.length() - 2
                 << s.back() << endl;
        }
    }

    return 0;
}