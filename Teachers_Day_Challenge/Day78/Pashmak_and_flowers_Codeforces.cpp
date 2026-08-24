/*
Problem: Pashmak and Flowers
Platform: Codeforces
Problem Number: 459B
Topic: Sorting, Counting, Combinatorics

Approach:
1. Read all flower values.
2. Find the minimum and maximum values.
3. Count how many flowers have the minimum value.
4. Count how many flowers have the maximum value.
5. The maximum possible difference is:
      maximum - minimum
6. If minimum == maximum:
      Every pair gives the same difference.
      Number of pairs = n * (n - 1) / 2
7. Otherwise:
      We must choose one minimum and one maximum.
      Number of ways = minCount * maxCount

Time Complexity: O(n)
- We scan the array to find the minimum and maximum
  and count their frequencies.

Space Complexity: O(n)
- The array is stored.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long minimum = *min_element(a.begin(), a.end());
    long long maximum = *max_element(a.begin(), a.end());

    long long minCount = 0;
    long long maxCount = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] == minimum)
            minCount++;

        if (a[i] == maximum)
            maxCount++;
    }

    long long difference = maximum - minimum;

    long long ways;

    if (minimum == maximum) {

        // Choose any two flowers
        ways = 1LL * n * (n - 1) / 2;
    }
    else {

        // Choose one minimum and one maximum
        ways = minCount * maxCount;
    }

    cout << difference << " " << ways;

    return 0;
}