/*
Problem: Little Elephant and the Bits
Platform: Codeforces
Problem Number: 258A
Topic: Greedy, String

Approach:
1. Read the binary string s.
2. Find the first occurrence of '0'.
3. Remove that '0'.
4. If there is no '0', remove the last character instead.
5. Print the resulting string.

Why remove the first '0'?
- Removing a 0 causes the digits after it to shift one position left.
- Removing an earlier 0 gives a larger number than removing a later 0.
- If all digits are 1, removing any 1 gives the same result,
  so removing the last one is sufficient.

Time Complexity: O(n)
- We scan the string once.

Space Complexity: O(n)
- The string is stored.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int pos = s.find('0');

    if (pos != string::npos) {
        s.erase(pos, 1);
    }
    else {
        // String contains only 1s
        s.pop_back();
    }

    cout << s;

    return 0;
}