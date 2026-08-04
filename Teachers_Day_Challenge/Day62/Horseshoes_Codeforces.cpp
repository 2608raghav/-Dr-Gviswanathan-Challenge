/*
Problem: Horseshoe
Platform: Codeforces
Problem Number: 228A
Topic: Set

Approach:
1. Read the colors of the four horseshoes.
2. Insert each color into a set.
   - A set automatically keeps only distinct values.
3. The number of horseshoes to buy is:
      4 - (number of distinct colors)
4. Print the result.

Time Complexity: O(1)
- Only four insertions into the set are performed.

Space Complexity: O(1)
- The set stores at most four elements.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    set<int> colors;

    for (int i = 0; i < 4; i++) {

        int color;
        cin >> color;
        colors.insert(color);
    }

    cout << 4 - colors.size();

    return 0;
}