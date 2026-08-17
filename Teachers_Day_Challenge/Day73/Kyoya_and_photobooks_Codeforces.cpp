/*
Problem: Kyoya and Photobooks
Platform: Codeforces
Problem Number: 554A
Topic: String, Set

Approach:
1. We have a string s of length n.
2. We can insert any lowercase English letter ('a' to 'z')
   at any position.
3. There are n + 1 possible insertion positions and 26
   possible letters.
4. However, different insertions can produce the same string.
5. To count only distinct photobooks:
   - Try every position from 0 to n.
   - Try every letter from 'a' to 'z'.
   - Insert the character into the string.
   - Store the resulting string in a set.
6. The size of the set is the required answer.

Time Complexity: O(26 * n * n)
- There are 26 * (n + 1) possible insertions.
- Creating/inserting a string takes O(n).
- Since n <= 20, this is easily fast enough.

Space Complexity: O(26 * n * n)
- The set stores all distinct resulting strings.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    set<string> st;

    for (int i = 0; i <= s.size(); i++) {

        for (char c = 'a'; c <= 'z'; c++) {

            string temp = s;

            temp.insert(temp.begin() + i, c);

            st.insert(temp);
        }
    }

    cout << st.size();

    return 0;
}