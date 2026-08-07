/*
Problem: Word Capitalization
Platform: Codeforces
Problem Number: 281A
Topic: String

Approach:
1. Read the input word.
2. Check the first character of the word.
3. Convert the first character to uppercase using toupper().
4. Leave all other characters unchanged.
5. Print the modified word.

Time Complexity: O(n)
- Reading the string takes O(n), although only the first
  character is modified.

Space Complexity: O(1)
- The string is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    s[0] = toupper(s[0]);

    cout << s;

    return 0;
}