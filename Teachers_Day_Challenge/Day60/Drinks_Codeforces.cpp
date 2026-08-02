/*
Problem: Drinks
Platform: Codeforces
Problem Number: 200B
Topic: Math, Implementation

Approach:
1. Read the number of drinks.
2. Initialize a variable to store the total percentage of orange juice.
3. Traverse all the drinks:
   - Read the percentage of orange juice in each drink.
   - Add it to the total.
4. Since equal amounts of each drink are mixed, the percentage of
   orange juice in the final mixture is simply the average.
5. Print the average with sufficient precision.

Time Complexity: O(n)
- The percentages are traversed once.

Space Complexity: O(1)
- Only a few variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    double sum = 0.0;

    for (int i = 0; i < n; i++) {

        double p;
        cin >> p;
        sum += p;
    }

    cout << fixed << setprecision(12) << sum / n;

    return 0;
}