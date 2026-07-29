/*
Problem: Team
Platform: Codeforces
Problem Number: 231A
Topic: Implementation

Approach:
1. Read the number of problems.
2. For each problem:
   - Read the opinions of the three friends.
   - Count how many of them are sure about the solution.
3. If at least two friends are sure,
   increment the answer.
4. After processing all problems, print the total count.

Time Complexity: O(n)
- n is the number of problems.

Space Complexity: O(1)
- Only a few integer variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int ans = 0;

    while (n--) {

        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c >= 2)
            ans++;
    }

    cout << ans;

    return 0;
}