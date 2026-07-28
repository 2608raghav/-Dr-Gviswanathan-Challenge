/*
Problem: Next Round
Platform: Codeforces
Topic: Array

Approach:
1. Read the number of participants (n) and the qualifying position (k).
2. Store the scores of all participants.
3. Identify the score of the k-th participant.
4. Traverse the scores:
   - Count every participant whose score is:
     a. Greater than or equal to the k-th score.
     b. Greater than 0.
5. Print the total count of qualified participants.

Time Complexity: O(n)
- The scores are traversed once.

Space Complexity: O(n)
- An array is used to store the scores.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> score(n);

    for (int i = 0; i < n; i++)
        cin >> score[i];

    int target = score[k - 1];
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (score[i] >= target && score[i] > 0)
            count++;
    }

    cout << count;

    return 0;
}