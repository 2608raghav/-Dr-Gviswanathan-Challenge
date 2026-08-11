/*
Problem: Friendly Number
Platform: Codeforces
Problem Number: 2197A
Topic: Math, Digit Manipulation

Approach:
1. A number y is friendly for x if:
      y - digitSum(y) = x
2. Therefore:
      y = x + digitSum(y)
3. Since x <= 10^9, the digit sum of a relevant number is
   at most 100.
4. Hence, we only need to check a small range of candidates
   starting from x.
5. For every candidate:
   - Calculate its digit sum.
   - Check whether candidate - digitSum(candidate) == x.
6. Count all valid candidates.

Time Complexity: O(1) per test case
- We check only a constant number of candidates
  (200 candidates).
- Each candidate has at most about 10 digits.

Space Complexity: O(1)
- No extra data structure is used.

*/

#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long n) {

    long long sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        long long x;
        cin >> x;

        int ans = 0;

        for (long long y = x; y <= x + 199; y++) {

            if (y - digitSum(y) == x)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}