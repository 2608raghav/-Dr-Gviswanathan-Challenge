/*
Problem: Watermelon
Platform: Codeforces
Problem Number: 4A
Topic: Math

Approach:
1. Read the weight of the watermelon.
2. If the weight is odd, it cannot be divided into two even parts.
3. If the weight is 2, it also cannot be divided into two positive even parts.
4. Otherwise:
   - The weight is even and greater than 2.
   - It can be split into two positive even integers.
5. Print "YES" if possible; otherwise, print "NO".

Time Complexity: O(1)
- Only a few arithmetic operations are performed.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int w;
    cin >> w;

    if (w > 2 && w % 2 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}