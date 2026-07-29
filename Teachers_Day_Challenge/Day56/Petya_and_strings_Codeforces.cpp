/*
Problem: Petya and Strings
Platform: Codeforces
Problem Number: 112A
Topic: String

Approach:
1. Read the two input strings.
2. Convert both strings to lowercase so that the comparison
   becomes case-insensitive.
3. Compare the strings lexicographically:
   - If the first string is smaller, print -1.
   - If the first string is greater, print 1.
   - Otherwise, print 0.
4. Return the result.

Time Complexity: O(n)
- n is the length of the strings.

Space Complexity: O(1)
- The comparison is performed in-place.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    for (char &c : s1)
        c = tolower(c);

    for (char &c : s2)
        c = tolower(c);

    if (s1 < s2)
        cout << -1;
    else if (s1 > s2)
        cout << 1;
    else
        cout << 0;

    return 0;
}