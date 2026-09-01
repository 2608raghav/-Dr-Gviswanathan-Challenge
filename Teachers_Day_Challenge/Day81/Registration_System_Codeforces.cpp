/*
Problem: Registration System
Platform: Codeforces
Problem Number: 4C
Topic: Hash Map, Implementation

Approach:
1. Use a map to store the number of times each username
   has appeared.
2. For every username:
   - If it does not exist in the map:
       Print "OK" and store its count as 1.
   - Otherwise:
       Print the username followed by its current count.
       Then increment its count.
3. Continue for all usernames.

Time Complexity: O(n log n)
- Each map operation takes O(log n).

Space Complexity: O(n)
- The map stores the usernames.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    map<string, int> mp;

    while (n--) {

        string user;
        cin >> user;

        if (mp.find(user) == mp.end()) {

            cout << "OK\n";
            mp[user] = 1;
        }
        else {

            cout << user << mp[user] << "\n";
            mp[user]++;
        }
    }

    return 0;
}