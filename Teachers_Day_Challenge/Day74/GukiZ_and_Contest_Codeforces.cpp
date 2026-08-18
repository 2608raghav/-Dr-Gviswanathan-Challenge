/*
Problem: GukiZ and Contest
Platform: Codeforces
Problem Number: 551A
Topic: Sorting, Map

Approach:
1. Store the original ratings in `org`.
2. Make a copy of the ratings in `sorted`.
3. Sort `sorted` in descending order.
4. Traverse the sorted array from the end.
5. Store the rank of each rating in a map:
      rating -> position
6. Since equal ratings are processed multiple times, the last
   occurrence gets the correct rank.
7. Traverse the original array and replace each rating with
   its corresponding rank.
8. Print the ranks in the original order.

Example:

Ratings:
1 3 3 2 5

Sorted descending:
5 3 3 2 1

Ranks:
5 -> 1
3 -> 2
2 -> 4
1 -> 5

Therefore:
1 3 3 2 5
↓
5 2 2 4 1

Time Complexity: O(n log n)
- Sorting takes O(n log n).
- Map insertion and lookup take O(log n).

Space Complexity: O(n)
- `org`, `sorted`, and `map` store O(n) elements.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, var;
    cin >> n;

    vector<int> org;
    vector<int> sorted;
    map<int, int> fr;

    while (n--) {

        cin >> var;

        org.push_back(var);
        sorted.push_back(var);
    }

    // Sort ratings in descending order
    sort(sorted.begin(), sorted.end(), greater<>());

    // Assign ranks
    for (int i = sorted.size() - 1; i >= 0; i--) {
        fr[sorted[i]] = i + 1;
    }

    // Convert original ratings into their ranks
    for (int i = 0; i < org.size(); i++) {
        org[i] = fr[org[i]];
    }

    // Print ranks
    for (int i = 0; i < org.size(); i++) {
        cout << org[i] << " ";
    }

    return 0;
}