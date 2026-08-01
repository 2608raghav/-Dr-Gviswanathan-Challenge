/*
Problem: Stones on the Table
Platform: Codeforces
Problem Number: 266A
Topic: String

Approach:
1. Read the number of stones and the string representing their colors.
2. Initialize a counter to store the number of stones to remove.
3. Traverse the string from the second character.
4. Compare each stone with its previous stone:
   - If both have the same color,
     increment the counter.
5. After traversing the string, print the counter.

Time Complexity: O(n)
- The string is traversed once.

Space Complexity: O(1)
- Only a counter is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;

    for (int i = 1; i < n; i++) {

        if (s[i] == s[i - 1])
            count++;
    }

    cout << count;

    return 0;
}