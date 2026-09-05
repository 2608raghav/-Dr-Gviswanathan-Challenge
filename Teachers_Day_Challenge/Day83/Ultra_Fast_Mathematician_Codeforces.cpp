/*
Problem: Ultra-Fast Mathematician
Platform: Codeforces
Problem Number: 61A
Topic: String, Bit Manipulation, Implementation

Approach:
1. Read the two binary strings.
2. Compare characters at every index.
3. If both characters are the same:
      Append '0' to the answer.
4. Otherwise:
      Append '1' to the answer.
5. Print the resulting binary string.

This is equivalent to the XOR operation:

0 XOR 0 = 0
0 XOR 1 = 1
1 XOR 0 = 1
1 XOR 1 = 0

Time Complexity: O(n)
- We compare every character once.

Space Complexity: O(n)
- We store the resulting string.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    string ans = "";

    // Compare every corresponding bit
    for (int i = 0; i < a.size(); i++) {

        if (a[i] == b[i]) {
            ans += '0';
        }
        else {
            ans += '1';
        }
    }

    cout << ans;

    return 0;
}