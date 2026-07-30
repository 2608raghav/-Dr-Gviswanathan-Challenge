/*
Problem: Nearly Lucky Number
Platform: Codeforces
Problem Number: 110A
Topic: Math, String

Approach:
1. Read the given number as a string.
2. Traverse each digit of the string.
3. Count how many digits are either '4' or '7'.
4. After counting:
   - If the count is exactly 4 or 7,
     print "YES".
   - Otherwise, print "NO".
5. Return the result.

Time Complexity: O(n)
- n is the number of digits.

Space Complexity: O(1)
- Only a counter is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string n;
    cin >> n;

    int count = 0;

    for (char c : n) {

        if (c == '4' || c == '7')
            count++;
    }

    if (count == 4 || count == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}