/*
Problem: Gravity Flip
Platform: Codeforces
Problem Number: 405A
Topic: Implementation, Sorting

Approach:
1. Read the number of columns.
2. Store the height of each column in an array.
3. When gravity acts from the right side, the shorter columns
   move toward the left and taller columns move toward the right.
4. Therefore, sort the array in ascending order.
5. Print the sorted array.

Time Complexity: O(n log n)
- Sorting the array takes O(n log n).

Space Complexity: O(n)
- The array stores n column heights.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    // Input the height of each column
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort columns after gravity flip
    sort(a.begin(), a.end());

    // Print the final arrangement
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}