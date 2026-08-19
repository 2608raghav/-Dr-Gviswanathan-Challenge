/*
Problem: Xenia and Divisors
Platform: Codeforces
Problem Number: 342A
Topic: Greedy, Frequency Array

Approach:
1. Count the frequency of every number.
2. Every valid group of 3 numbers can only be:
      1 2 4
      1 2 6
      1 3 6

3. First create groups of:
      1 3 6
   because 3 can only be used in this combination.

4. Then create groups of:
      1 2 4

5. Finally create groups of:
      1 2 6

6. If all numbers are used, print the groups.
   Otherwise, the answer is -1.

Time Complexity: O(n)
- We count frequencies and process only values up to 7.

Space Complexity: O(1)
- The frequency array has fixed size.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> fr(8, 0);

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        fr[x]++;
    }

    vector<vector<int>> ans;

    // First make 1 3 6 groups
    while (fr[3] > 0) {

        if (fr[1] == 0 || fr[6] == 0) {
            cout << -1;
            return 0;
        }

        fr[1]--;
        fr[3]--;
        fr[6]--;

        ans.push_back({1, 3, 6});
    }

    // Then make 1 2 4 groups
    while (fr[4] > 0) {

        if (fr[1] == 0 || fr[2] == 0) {
            cout << -1;
            return 0;
        }

        fr[1]--;
        fr[2]--;
        fr[4]--;

        ans.push_back({1, 2, 4});
    }

    // Finally make 1 2 6 groups
    while (fr[6] > 0) {

        if (fr[1] == 0 || fr[2] == 0) {
            cout << -1;
            return 0;
        }

        fr[1]--;
        fr[2]--;
        fr[6]--;

        ans.push_back({1, 2, 6});
    }

    // Check whether all numbers were used
    for (int i = 1; i <= 7; i++) {

        if (fr[i] != 0) {
            cout << -1;
            return 0;
        }
    }

    // Print the groups
    for (auto group : ans) {

        cout << group[0] << " "
             << group[1] << " "
             << group[2] << "\n";
    }

    return 0;
}