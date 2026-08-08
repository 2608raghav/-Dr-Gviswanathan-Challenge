/*
Problem: Soft Drinking
Platform: Codeforces
Problem Number: 151A
Topic: Math, Implementation

Approach:
1. Calculate how many drinks can be made:
      totalDrink = (n * k * l) / nl
2. Calculate how many lime slices are available for toasts:
      totalLime = c * d
3. Calculate how many grams of salt are available:
      totalSalt = p / np
4. The number of toasts possible is limited by the minimum of:
      - totalDrink
      - totalLime
      - totalSalt
5. Each toast requires one `nl` milliliters of drink,
   so divide the limiting number of toasts by `n`.
6. Print the number of toasts each friend can make.

Time Complexity: O(1)
- Only arithmetic operations are performed.

Space Complexity: O(1)
- No extra space is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    long long drink = (k * l) / nl;
    long long lime = c * d;
    long long salt = p / np;

    long long totalToasts = min({drink, lime, salt});

    cout << totalToasts / n;

    return 0;
}