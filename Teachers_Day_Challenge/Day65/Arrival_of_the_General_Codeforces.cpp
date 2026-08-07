/*
Problem: Arrival of the General
Platform: Codeforces
Problem Number: 144A
Topic: Array, Greedy

Approach:
1. Find:
   - The position of the first occurrence of the maximum element.
   - The position of the last occurrence of the minimum element.
2. The maximum element needs to move to the first position.
   - Number of swaps required = maxIndex.
3. The minimum element needs to move to the last position.
   - Number of swaps required = (n - 1 - minIndex).
4. If the maximum is located after the minimum, moving the maximum
   to the front will shift the minimum one position to the left.
   Therefore, subtract 1 from the total swaps.
5. Return the total number of swaps.

Time Complexity: O(n)
- The array is traversed once to find the required positions.

Space Complexity: O(n)
- The input array is stored.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxIndex = 0;
    int minIndex = 0;

    // First occurrence of maximum
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[minIndex])
            minIndex = i;
    }

    int ans = maxIndex + (n - 1 - minIndex);

    if (maxIndex > minIndex)
        ans--;

    cout << ans;

    return 0;
}