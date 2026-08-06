/*
Problem: Sereja and Dima
Platform: Codeforces
Problem Number: 381A
Topic: Greedy, Two Pointers

Approach:
1. Read the number of cards and their values.
2. Initialize two pointers:
   - left at the beginning.
   - right at the end.
3. Alternate turns between Sereja and Dima.
4. On each turn:
   - Choose the larger value between the leftmost and rightmost card.
   - Add the chosen value to the current player's score.
   - Move the corresponding pointer.
5. Continue until all cards are taken.
6. Print the final scores of Sereja and Dima.

Time Complexity: O(n)
- Each card is selected exactly once.

Space Complexity: O(1)
- Only pointers and score variables are used.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    int left = 0;
    int right = n - 1;

    int sereja = 0;
    int dima = 0;

    bool turn = true;

    while (left <= right) {

        int value;

        if (cards[left] >= cards[right]) {
            value = cards[left];
            left++;
        }
        else {
            value = cards[right];
            right--;
        }

        if (turn)
            sereja += value;
        else
            dima += value;

        turn = !turn;
    }

    cout << sereja << " " << dima;

    return 0;
}