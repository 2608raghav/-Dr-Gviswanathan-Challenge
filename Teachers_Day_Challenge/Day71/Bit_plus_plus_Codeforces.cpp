/*
Problem: Bit++
Platform: Codeforces
Problem Number: 282A
Topic: Implementation, String

Approach:
1. Initialize a variable x = 0.
2. Read the number of operations.
3. For each operation:
   - If the statement contains '+', increment x.
   - Otherwise, decrement x.
4. After processing all operations, print x.

Time Complexity: O(n)
- Each operation is checked once.

Space Complexity: O(1)
- Only the variable x is used.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int x = 0;

    while (n--) {

        string s;
        cin >> s;

        if (s.find('+') != string::npos)
            x++;
        else
            x--;
    }

    cout << x;

    return 0;
}