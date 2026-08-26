/*
Problem: XXXXX
Platform: Codeforces
Problem Number: 1364A
Topic: Array, Greedy, Number Theory

Approach:
1. Calculate the total sum of the array.
2. If sum % x != 0:
      The entire array is valid.
      Answer = n.
3. Otherwise:
      Find:
        - first element not divisible by x
        - last element not divisible by x
4. Remove either:
      - the prefix ending at the first such element
      - the suffix starting at the last such element
5. Keep whichever remaining subarray is longer.
6. If no element is not divisible by x, answer = -1.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        long long sum = 0;

        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++) {

            cin >> a[i];

            sum += a[i];

            if (a[i] % x != 0) {

                if (first == -1)
                    first = i;

                last = i;
            }
        }

        // Entire array has a sum not divisible by x
        if (sum % x != 0) {

            cout << n << '\n';
        }

        // Every element is divisible by x
        else if (first == -1) {

            cout << -1 << '\n';
        }

        else {

            // Remove prefix OR remove suffix
            int removePrefix = first + 1;
            int removeSuffix = n - last;

            int answer = n - min(removePrefix, removeSuffix);

            cout << answer << '\n';
        }
    }

    return 0;
}