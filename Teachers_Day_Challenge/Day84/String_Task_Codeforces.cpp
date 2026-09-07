/*
Problem: String Task
Platform: Codeforces
Problem Number: 118A
Topic: String, Implementation

Approach:
1. Read the input string.
2. Traverse every character of the string.
3. Convert each character to lowercase.
4. Check whether the character is a vowel:
      a, e, i, o, u, y
5. If it is a vowel:
      Ignore it.
6. Otherwise:
      Add '.' before the character.
      Add the consonant to the answer.
7. Print the final string.

Example:

Input:
Codeforces

After converting to lowercase:
codeforces

Remove vowels:
c d f r c s

Add '.' before every remaining character:
.c.d.f.r.c.s

Time Complexity: O(n)
- Every character is processed once.

Space Complexity: O(n)
- The answer string can store up to O(n) characters.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    string ans = "";

    
    for (char c : s) {

        
        c = tolower(c);

        
        if (c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u' ||
            c == 'y') {

            
            continue;
        }

        
        ans += '.';
        ans += c;
    }

    cout << ans;

    return 0;
}

