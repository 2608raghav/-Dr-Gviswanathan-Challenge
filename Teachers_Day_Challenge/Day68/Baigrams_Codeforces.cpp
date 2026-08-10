/*
Problem: Bigrams
Platform: Codeforces
Problem Number: 2242A
Topic: Strings, Sorting

Approach:
1. A bigram consists of two adjacent characters.
2. We need to determine whether some bigram can occur at least twice.
3. There are two possibilities:
   
   Case 1: The same character forms the bigram:
      aa
   To get "aa" twice, we need at least 3 copies of 'a'.
   
   Case 2: Two different characters form the bigram:
      ab
   To get "ab" twice, we need at least two copies of one
   character and at least one copy of the other.
   This is possible whenever at least two different letters
   have frequency >= 2.

4. Therefore:
   - If any character occurs at least 3 times, answer YES.
   - Otherwise, if at least two characters occur at least 2 times,
     answer YES.
   - Otherwise, answer NO.

Time Complexity: O(k)
- k <= 10, so we examine the frequency array once.

Space Complexity: O(k)
- A frequency array of size k is used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int k;
        cin >> k;

        vector<long long> cnt(k);

        for (int i = 0; i < k; i++)
            cin >> cnt[i];

        bool possible = false;
        int atLeastTwo = 0;

        for (int i = 0; i < k; i++) {

            // We can create xx twice using 3 copies.
            if (cnt[i] >= 3)
                possible = true;

            if (cnt[i] >= 2)
                atLeastTwo++;
        }

        // Two different characters can create
        // the same ordered bigram twice.
        if (atLeastTwo >= 2)
            possible = true;

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}