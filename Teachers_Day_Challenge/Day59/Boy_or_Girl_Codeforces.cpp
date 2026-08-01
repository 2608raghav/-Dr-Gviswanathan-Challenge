/*
Problem: Boy or Girl
Platform: Codeforces
Problem Number: 236A
Topic: String, Set

Approach:
1. Read the username.
2. Insert every character of the username into a set.
   - A set automatically stores only distinct characters.
3. Count the number of distinct characters.
4. If the count is even, print "CHAT WITH HER!".
5. Otherwise, print "IGNORE HIM!".

Time Complexity: O(n log n)
- n is the length of the username.
- Each insertion into the set takes O(log n).

Space Complexity: O(n)
- The set stores all distinct characters.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    set<char> st;

    for (char c : s)
        st.insert(c);

    if (st.size() % 2 == 0)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";

    return 0;
}