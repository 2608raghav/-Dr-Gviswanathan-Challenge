/*
Problem: BerSU Ball
Platform: Codeforces
Problem Number: 489B
Topic: Greedy, Sorting, Two Pointers

Approach:
1. Sort both arrays:
   - Boys' skill levels
   - Girls' skill levels
2. Use two pointers:
   - i -> current boy
   - j -> current girl
3. Compare their skill levels:
   - If abs(boy[i] - girl[j]) <= 1:
       They can form a pair.
       Increment answer and move both pointers.
   - If boy[i] < girl[j] - 1:
       The boy is too weak for this girl.
       Move to the next boy.
   - Otherwise:
       The girl is too weak for this boy.
       Move to the next girl.
4. Continue until one array is exhausted.

Time Complexity: O(n log n + m log m)
- Sorting dominates the complexity.

Space Complexity: O(1) auxiliary space
- Apart from the input arrays.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> boys(n);

    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }

    int m;
    cin >> m;

    vector<int> girls(m);

    for (int i = 0; i < m; i++) {
        cin >> girls[i];
    }

    // Sort both skill arrays
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int i = 0;
    int j = 0;
    int ans = 0;

    while (i < n && j < m) {

        if (abs(boys[i] - girls[j]) <= 1) {

            // They can form a pair
            ans++;
            i++;
            j++;
        }

        else if (boys[i] < girls[j]) {

            // Boy is too weak
            i++;
        }

        else {

            // Girl is too weak
            j++;
        }
    }

    cout << ans;

    return 0;
}