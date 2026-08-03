/*
Problem: Presents
Platform: Codeforces
Problem Number: 136A
Topic: Array

Approach:
1. Read the number of friends.
2. Create an answer array of size n + 1.
3. For each friend i:
   - Read the friend p who receives i's present.
   - Store i at position p in the answer array.
4. After processing all friends, the answer array represents
   who gave a present to each friend.
5. Print the answer array from index 1 to n.

Time Complexity: O(n)
- The array is traversed once.

Space Complexity: O(n)
- An additional array of size n + 1 is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++) {

        int p;
        cin >> p;

        ans[p] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}