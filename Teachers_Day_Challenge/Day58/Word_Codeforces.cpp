/*
Problem: Word
Platform: Codeforces
Problem Number: 59A
Topic: String

Approach:
1. Read the input word.
2. Traverse the word and count:
   - Number of uppercase letters.
   - Number of lowercase letters.
3. Compare the two counts:
   - If uppercase letters are more, convert the entire word to uppercase.
   - Otherwise (including when the counts are equal),
     convert the entire word to lowercase.
4. Print the modified word.

Time Complexity: O(n)
- n is the length of the word.

Space Complexity: O(1)
- The string is modified in place.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int upper = 0, lower = 0;

    for (char c : s) {

        if (isupper(c))
            upper++;
        else
            lower++;
    }

    if (upper > lower) {

        for (char &c : s)
            c = toupper(c);
    }
    else {

        for (char &c : s)
            c = tolower(c);
    }

    cout << s;

    return 0;
}